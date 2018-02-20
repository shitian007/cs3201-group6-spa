#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Pattern.h"

using namespace std::tr1;

class PKB {
public:
	/*  PKB Structure*/
	unordered_map<int, std::vector<std::vector<int>>> tables[7];
	unordered_map<int, std::string> nameTables[2];

	/* PKB Operations */
	bool insertToTable(int, int, std::vector<std::vector<int>>);
	int insertToNameTable(int, std::string);
	std::vector<std::vector<int>> getFromTable(int, int);
	std::string getFromNameTable(int, int);
	std::vector<int> getAllVariables();
	std::vector<int> getAllStatements();
	std::vector<int> getAllProcedures();

	/* Accessor Operations */
	std::string getProcedureName(int);
	std::string getVariableName(int);
	int getProcedureId(std::string);
	int getVariableId(std::string);

	/* Follows Operations */
	int getFollowsBefore(int);
	int getFollowsAfter(int);
	std::vector<int> getFollowsBeforeStar(int);
	std::vector<int> getFollowsAfterStar(int);
	bool checkFollows(int, int);
	bool checkFollowsStar(int, int);
	std::vector<std::vector<int>> getAllFollows();
	unordered_map<int, std::vector<int>> getAllFollowsStar();

	/* Parent Operations */
	int getParent(int);
	std::vector<int> getParentStar(int);
	std::vector<int> getChildren(int);
	std::vector<int> getChildrenStar(int);
	bool checkParent(int, int);
	bool checkParentStar(int, int);
	std::vector<std::vector<int>> getAllParent();
	unordered_map<int, std::vector<int>> getAllParentStar();

	/* Uses Operations */
	std::vector<int> getUsesVariablesFromStatement(int);
	std::vector<int> getStatementsFromUsesVariable(int);
	std::vector<int> getUsesVariablesFromProcedure(int);
	std::vector<int> getProceduresFromUsesVariable(int);
	unordered_map<int, std::vector<int>> getAllStatementUsesVariables();
	unordered_map<int, std::vector<int>> getAllVariableUsesStatements();
	unordered_map<int, std::vector<int>> getAllProcedureUsesVariables();
	unordered_map<int, std::vector<int>> getAllVariableUsesProcedures();
	bool checkStatementUsesVariable(int, int);
	bool checkProcedureUsesVariable(int, int);

	/* Modifies Operations */
	std::vector<int> getModifiesVariablesFromStatement(int);
	std::vector<int> getStatementFromModifiesVariables(int);
	unordered_map<int, std::vector<int>> getAllStatementModifiesVariables();
	unordered_map<int, std::vector<int>> getAllModifiesVariableStatements();
	bool checkStatementModifiesVariable(int, int);

	/* Pattern Operations */
	std::vector<int> getStatementsWithPattern(Pattern);
	bool checkStatementsWithPattern(Pattern);

};