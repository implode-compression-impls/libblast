#include <string>
#include <iostream>
#include <memory>
#include <filesystem>

#include <stdio.h>
#include <blast.h>

#include <fileTestSuite/fileTestSuite.h>
#include <fileTestSuite/fileTestSuiteRunner.hpp>
#include <stdint.h>


//#include <fileTestSuite/fileTestSuite.h>

unsigned inf(void *how, unsigned char **buf){
	FTSSpanT *input_span  = (FTSSpanT *) how;
	std::cout << "inf printed: ";
	*buf = (uint8_t*) input_span->data();
	return input_span->size();
}


int outf(void *how, unsigned char *buf, unsigned len){
	OutputBufferTester *outBuffTester  = (OutputBufferTester *) how;

	std::cout << "outf printed: " << *buf << std::endl;

	outBuffTester->testChunkProcessing(buf, len);
	return false;
}


struct BlastTestingContext: public TesteeSpecificContext{
	decltype(blast(inf, nullptr, nullptr, nullptr, nullptr, nullptr)) resultCode;
	unsigned int left;

	BlastTestingContext(): TesteeSpecificContext(){
		shouldSwapChallengeResponse = true;
	}

	virtual ~BlastTestingContext() = default;
	virtual void verifyAxillaryResults(FTSTestToolkit* ctx) override {
		ctx->tk->expectEqual(this->resultCode, BLAST_SUCCESS);
		ctx->tk->expectEqual(this->left, 0u);
	}
	virtual void executeTestee(pseudospan &challenge_data_span, OutputBufferTester &outBuffTester) override {
		left = 0;
		resultCode = blast(inf, &challenge_data_span, &outf, (void*) &outBuffTester, &this->left, nullptr);
	}
};

TesteeSpecificContext* testeeSpecificContextFactory(){
	return new BlastTestingContext();
}
