#pragma once
#include <unordered_map>
#include "Clause.h"
#include "Pattern.h"
#include "Utils.h"

class ClauseResults {
private:
	/* Boolean for when both params are concrete */
	bool valid;
	/* Solely used for pattern */
	vector<int> assignmentsEnts;
public:
	Param entRef;
	Param lhs;
	Param rhs;

	/* 2d table storing results from pkb */
	vector<Param> tableParams;
	vector<vector<int>> results;

	// Instantiation
	void ClauseResults::instantiateClause(Clause clause);
	void ClauseResults::instantiatePattern(Pattern pattern);

	// Setter methods
	void ClauseResults::setResults(vector<vector<int>> &pkbResults);
	void ClauseResults::setValid(bool validity);
	void ClauseResults::clearResults();
	void ClauseResults::clearParamsTable();

	// Getter methods
	bool ClauseResults::isValid();
	bool ClauseResults::hasResults();
	int ClauseResults::numParamsInResult();

	// Helpers
	void ClauseResults::removeALLSyns();

};

struct IntermediateTable {
	bool hasResults;
	vector<Param> tableParams;
	vector<vector<int>> resultsTable;
	vector<Param> withTableParams;
	vector<vector<int>> withResultsTable; // Storage of independent with results

	void instantiateTable() {
		hasResults = true;
	};

	void setTableParams(vector<Param> params) {
		tableParams = params;
	};

	void addTableParams(Param p) {
		tableParams.push_back(p);
	};

	void setResultsTable(vector<vector<int>> &table) {
		resultsTable = table;
	};

	void addWithTableParams(Param p) {
		withTableParams.push_back(p);
	}

	void setWithResultsTable(vector<vector<int>> &table) {
		withResultsTable = table;
	}
};
