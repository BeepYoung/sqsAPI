#include "Sqs.h"


Sqs::Sqs(int sourceCounter, int bufferSize, int deviceCounter, int requestCount):buffer(bufferSize,sourceCounter)
	,sourceCounter(sourceCounter)
	,bufferSize(bufferSize)
	,deviceCounter(deviceCounter)
{
	for (int i = 0; i < sourceCounter; i++) {
		int randInt = rand() % 5 + 1;
		sources.push_back(Source(randInt, i+1));
		sources.at(i).clk();		//������� �������� ������ �����
	}
	for (int i = 0; i < deviceCounter; i++) {
		int randIntA = 1;//(rand() % 100) + 1;
		int randIntB = 2;//(rand() % 200) + 1;
	//	std::cout << "rand a " << randIntA << "\tb " << randIntB << "\n";
		devices.push_back(Device(randIntA, randIntB, i));
	}
	this->requestCount = requestCount;
}

void Sqs::work()
{
	//std::cout << "generate requests\n";
	//system("pause");

	SettingManager settingDispatcher;
	GettingManager gettingDispatcher;// (devices, buffer, sourceCounter);
	//buffer.printBuffer();
	std::cout << "\n";
	for (int requestCounter = 0; requestCounter < requestCount; requestCounter++) {
		int currentSrc = earliestSourceNumber(sources);
		Request currentReq = sources.at(currentSrc).generate();
		sources.at(currentSrc).clk();


		settingDispatcher.putElement(buffer, currentReq);
		/*std::cout.precision(4);
		std::cout << currentReq.getGenerationTime() << "\t" << currentReq.getNumber().SOURCE_NUM << "\t" << currentReq.getNumber().REQUEST_NUM << "\n";
		*/
		
		float availableTime = devices.at(gettingDispatcher.firstAvailableDeviceNum(devices)).getVacationTime();

		if (currentReq.getGenerationTime() > availableTime) {
			buffer.printBuffer();
			gettingDispatcher.getRequest(devices, buffer, sourceCounter);
		}
		//statcenter??? getStatistics(buffer,devices,sources)???
		std::cout << "COUNTER REQUESTS IN SYSTEM = " << requestCounter << "\n";
	}
//	buffer.printBuffer();
}




int Sqs::earliestSourceNumber(std::vector<Source> sources) 
{
	int n = 0;
	for (int i = 0; i < sourceCounter; i++) {
		if (sources.at(i).getGenerationTime() < sources.at(n).getGenerationTime()) {
			n = i;
		}
	}
	return n;
}
