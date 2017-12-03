#include <iostream>

#include "llvm/Support/Debug.h"

/* for stat support */
#include "llvm/ADT/Statistic.h"

#include "llvm/Pass.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/CFG.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Utils/Cloning.h"

using namespace llvm;

namespace {

	class MyCFGPass : public llvm::FunctionPass {

		public:
			static char ID;
			MyCFGPass() : llvm::FunctionPass(ID) {}

			bool runOnFunction(Function &F) override {
                outs() << "Hi, my name is: " << F.getName() << "\n";
            }
    };
}

char MyCFGPass::ID = 1;
static RegisterPass<MyCFGPass> Z("mycfgpass",
		"Dumbo Pass which does nothing",
		false, // modifies the CFG!
		false);

/* for clang pass registration
*/
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

static void registerClangPass(const PassManagerBuilder &,
		legacy::PassManagerBase &PM) {
	PM.add(new MyCFGPass());
}
static RegisterStandardPasses
RegisterClangPass(PassManagerBuilder::EP_EarlyAsPossible,
		registerClangPass);
