#include "TestWrapper.h"

// implementation code of WrapperFactory - do NOT modify the next 5 lines
AbstractWrapper* WrapperFactory::wrapper = 0;
AbstractWrapper* WrapperFactory::createWrapper() {
	if (wrapper == 0) wrapper = new TestWrapper;
	return wrapper;
}
// Do not modify the following line
volatile bool TestWrapper::GlobalStop = false;

// a default constructor
TestWrapper::TestWrapper() {
	// create any objects here as instance variables of this class
	// as well as any initialization required for your spa program
	//preprocessor.setEvaluator(evaluator);
}

// method for parsing the SIMPLE source

void TestWrapper::parse(std::string filename) {
	pkb = parser.Parse(filename, pkb);
	de.extract(pkb);
	evaluator.setPKB(pkb);
}

// method to evaluating a query
void TestWrapper::evaluate(std::string query, std::list<std::string>& results) {
	preprocessor.setEvaluator(evaluator);
	preprocessor.preprocessQuery(query);
	results = evaluator.evaluateQuery();
}
