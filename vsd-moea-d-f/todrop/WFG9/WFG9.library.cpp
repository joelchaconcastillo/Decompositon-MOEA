#include "WFG9.h"

extern "C" {
	Individual *maker(){
		return new WFG9();
	}
}
