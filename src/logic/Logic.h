/*
 * Logic.h
 *
 *  Created on: 16 lut 2017
 *      Author: tedlar
 */

#ifndef LOGIC_LOGIC_H_
#define LOGIC_LOGIC_H_

#include <src/interfaces/ILogic.h>
#include <src/interfaces/IController.h>
#include <src/interfaces/IKeyGameHandler.h>
#include <src/interfaces/IKeyManager.h>
#include <src/interfaces/IObject.h>

#include <map>


class Logic : public ILogic {
public:
	~Logic();

	void create();
	void configure(int& argc, char **argv);
	void initialize();
	void start();

public slots:
	void onSendKeySignal(KeyType);

private:
	uint8_t agentNumber_;
	std::shared_ptr<IController>     controller_;
	std::shared_ptr<IKeyGameHandler> keyGameHandler_;
	std::shared_ptr<IKeyManager>     keyManager_;
	std::map<uint8_t, std::shared_ptr<IObject>> objectsMap_;

private:
	void createController();
	void createKeyGameHandler();
	void createKeyManager();
	void createObjects();

	void configureController();
	void configureKeyGameHandler();

	void initializeController();

	void startController();
	void startKeyGameHandler();
};

#endif // LOGIC_LOGIC_H_
