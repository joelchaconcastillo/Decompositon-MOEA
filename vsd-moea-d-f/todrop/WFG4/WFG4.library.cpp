#include "WFG4.h"

extern "C" {
	Individual *maker(){
		return new WFG4();
	}
}
