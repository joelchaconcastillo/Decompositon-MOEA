#include "WFG3.h"

extern "C" {
	Individual *maker(){
		return new WFG3();
	}
}
