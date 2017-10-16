#include "Sqs.h"


Sqs::Sqs(int sourceCounter, int bufferSize, int deviceCounter, int requestCount):buffer(bufferSize,sourceCounter)
	,sourceCounter(sourceCounter)
	,bufferSize(bufferSize)
	,deviceCounter(deviceCounter)
{
	for (int i = 0; i < sourceCounter; i++) {
		int randInt = rand() % 5 + 1;
		sources.push_back(Source(randInt, i+1));
		sources.at(i).clk();		//система начинает раобту здесь
	}
	for (int i = 0; i < deviceCounter; i++) {
		int randIntA = rand() % 5 + 1;
		int randIntB = rand() % 5 + 1;
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
	buffer.printBuffer();
	for (int requestCounter = 0; requestCounter < requestCount; requestCounter++) {
		int currentSrc = earliestSourceNumber(sources);
		Request currentReq = sources.at(currentSrc).generate();
		sources.at(currentSrc).clk();


		settingDispatcher.putElement(buffer, currentReq);
		/*std::cout.precision(4);
		std::cout << currentReq.getGenerationTime() << "\t" << currentReq.getNumber().SOURCE_NUM << "\t" << currentReq.getNumber().REQUEST_NUM << "\n";
		*/
	//	gettingDispatcher.getRequest(devices, buffer,sourceCounter);
		//statcenter??? getStatistics(buffer,devices,sources)???
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
