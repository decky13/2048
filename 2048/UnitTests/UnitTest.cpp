#include "GameLogic.h"
#include "LogicCell.h"

#include <iostream>

//TESTS
//TESTERS HELPERS
static std::vector<LogicCell*> createLine(unsigned a0, unsigned a1, unsigned a2, unsigned a3)
{
	std::vector<LogicCell*> line;
	line.push_back(new LogicCell(0, 0));
	line.back()->setValue(a0);

	line.push_back(new LogicCell(1, 0));
	line.back()->setValue(a1);

	line.push_back(new LogicCell(2, 0));
	line.back()->setValue(a2);

	line.push_back(new LogicCell(3, 0));
	line.back()->setValue(a3);

	return line;
}

static bool checkLine(const std::vector<LogicCell*>& lineToCheck, const std::vector<LogicCell*>& refLine)
{
	for (std::size_t i = 0; i < lineToCheck.size(); ++i)
	{
		if (lineToCheck[i]->getValue() != refLine[i]->getValue()) throw;
	}
	return true;
}

void gameLogicTest()
{
	GameLogic gameLogic{};

	std::vector<LogicCell*> testLine;
	std::vector<LogicCell*> refLine;

	//COMPRESS
	testLine = createLine(2, 2, 2, 2);
	refLine = createLine(2, 2, 2, 2);
	gameLogic.compressOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(2, 0, 2, 2);
	refLine = createLine(0, 2, 2, 2);
	gameLogic.compressOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(0, 2, 0, 2);
	refLine = createLine(0, 0, 2, 2);
	gameLogic.compressOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(2, 0, 0, 0);
	refLine = createLine(0, 0, 0, 2);
	gameLogic.compressOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(2, 2, 0, 2);
	refLine = createLine(0, 2, 2, 2);
	gameLogic.compressOneLine(testLine);
	checkLine(testLine, refLine);

	//RESOLVE
	testLine = createLine(2, 2, 2, 2);
	refLine = createLine(0, 4, 0, 4);
	gameLogic.resolveOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(2, 2, 0, 2);
	refLine = createLine(0, 4, 0, 2);
	gameLogic.resolveOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(0, 0, 4, 2);
	refLine = createLine(0, 0, 4, 2);
	gameLogic.resolveOneLine(testLine);
	checkLine(testLine, refLine);

	testLine = createLine(2, 0, 2, 0);
	refLine = createLine(2, 0, 2, 0);
	gameLogic.resolveOneLine(testLine);
	checkLine(testLine, refLine);
}

int main()
{
	gameLogicTest();

   int justToWait;
   std::cin >> justToWait;
	return 0;
}

//END TESTS