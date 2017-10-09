#ifndef SETTING_MANAGER_H
#define SETTING_MANAGER_H

#include <iostream>

#include "Request.h"
#include "Buffer.h"

class SettingManager {
public:
	void sendRequest(Buffer& buffer);
	void putElement(Iterator it);
};

#endif

//Ставит заявки в буфер
// буфер должен предоставить функционал
//для опрелеления состояния
//есть ли место isFull()
//если есть то ставим на свободное
//если нет то кикаем заявку и помещаем новую