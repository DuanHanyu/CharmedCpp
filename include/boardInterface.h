#ifndef _BOARDINTERFACE_H_
#define _BOARDINTERFACE_H_ 1
#include "boardAnalyse.h"

#define INTER_MAX_INPUT 256

using std::cin;
using std::getline;
using std::string;

class BoardInterface {
public:
	BoardAnalyse* analyse;	// this might be more important?
	BoardRecord	  record;

	BoardInterface();
	BoardInterface(BoardAnalyse& hb);
	virtual ~BoardInterface();

	void generate(short c, short r, short w) { analyse = new BoardAnalyse(c, r, w); }

	// general
	string getInput(const string mode);
	string getInput(char plr, double& inputTime);
	short  getCustomInput(const string item);
	bool   getStateFromInput();
	bool   transformInput(char** dest, vector<string>& src, const int cols, const int rows);

	// mode
	string addMode();
	string reverseMode();
	virtual string debugMode(oneMove& byPlayer);
	// string normalMode();
	string settingsMode();
	string defaultSettings();
	string otherSettings();
	string playMode();
	string playBackMode();
	string customMode();
	virtual bool controlMode();
	string showRoutesMode();
	string selfPlayMode();

	// ask & do
	virtual bool askToReverse(bool yes);	// if yes == true, then default yes
	virtual void askToSaveBoard(bool yes);
	void importNewBoard();

	// info
	string getHelp(string mode);
	string getInfo(string input);

	// refresh
	void refreshRecord(const BoardRecord& record_) { record = record_; }

	// show
	void showComment(oneMove& move);

	// check
	virtual bool isOver(const oneMove& move);
	int autoTestMode(int startMove);
};

#endif
