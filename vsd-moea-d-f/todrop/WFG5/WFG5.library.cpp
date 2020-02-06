#include "WFG5.h"

extern "C" {
	Individual *maker(){
		return new WFG5();
	}
}
