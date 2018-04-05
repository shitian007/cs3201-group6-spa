#pragma once

#include "../source/PKB.h"

class DesignExtractor
{
public:
	bool extract(PKB &);
	
private:
	void extractNext(PKB &);
	void processStatementList(PKB &, int, int, int, int);
	void extractCallsInverse(PKB &);
	void extractCallsStar(PKB &);
	void extractCallStatements(PKB &);
	void extractUsesModifies(PKB &);

	void precomputeWithProcNameVarName(PKB&);
	void precomputeWithProcNameCallProcName(PKB&);
	void precomputeWithVarNameCallProcName(PKB&);
	void precomputeWithStmtNoConstValue(PKB&);

	void countFollows(PKB &);
	void countFollowsStar(PKB &);
	void countUsesProcedure(PKB &);
	void countUsesStatement(PKB &);
	void countModifiesProcedure(PKB &);
	void countModifiesStatement(PKB &);
	void countParent(PKB &);
	void countParentStar(PKB &);
	void countCalls(PKB &);
	void countCallsStar(PKB &);
	void countAffects(PKB &);
	void countAffectsStar(PKB &);
	void countNext(PKB &);
	void countNextStar(PKB &);
};

