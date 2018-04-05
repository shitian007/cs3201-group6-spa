#pragma once

#include "QueryObject.h"
#include "QueryContent.h"
#include "QueryEvaluator.h"
#include <string>
#include <vector>

class QueryQueuer
{

private:
	bool validQuery;
	QueryContent qc;
	QueryEvaluator _evaluator;
	list<string> invalidQueryMessage;

public:
	QueryQueuer();
	bool isValidQuery();
	void setQueryContent(QueryContent);
	QueryContent getQueryContent();
	void setEvaluator(QueryEvaluator &);
	void setInvalidQuery(string);
	list<string> evaluateQueries();
	std::vector<QueryObject> parseQueryContent();
	std::vector<Clause> parseClauseTree(ClauseNode);
	std::vector<Clause> parseWithClauseTree(ClauseNode);
	std::vector<Pattern> parsePatternTree(ClauseNode);
};
