#include "Sqs.h"


Sqs::Sqs(int sourceCounter, int bufferSize, int deviceCounter, int requestCount):buffer(bufferSize)
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
		int randIntA = rand() % 5 + 1;
		int randIntB = rand() % 5 + 1;
		devices.push_back(Device(randIntA, randIntB, i+1));
	}
	this->requestCount = requestCount;
}

void Sqs::work() 
{
	std::cout << "generate requests\n";
	system("pause");

	for (int requestCounter = 0; requestCounter < requestCount; requestCounter++) {
		int currentSrc = earliestSourceNumber(sources);
		Request currentReq = sources.at(currentSrc).generate();
		sources.at(currentSrc).clk();

		SettingManager settingDispatcher;
		settingDispatcher.putElement(buffer, currentReq);
		std::cout << currentReq.getGenerationTime() << "\t" << currentReq.getNumber().SOURCE_NUM << "\t" << currentReq.getNumber().REQUEST_NUM << "\n";
	}
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