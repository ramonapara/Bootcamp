#include <stdio.h>
#define DBG_PRINT(debugLevel,format,...) printf("[%d][(%s)][%d]: ",debugLevel,__FILE__,__LINE__), printf((format),__VA_ARGS__);

int main()
{
	DBG_PRINT(5," My value is %d ",5);
	return 0;
}
