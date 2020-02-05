#include "WFG2.h"

extern "C" {
	Individual *maker(){
		return new WFG2();
	}
}
