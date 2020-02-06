#include "WFG1.h"

extern "C" {
	Individual *maker(){
		return new WFG1();
	}
}
