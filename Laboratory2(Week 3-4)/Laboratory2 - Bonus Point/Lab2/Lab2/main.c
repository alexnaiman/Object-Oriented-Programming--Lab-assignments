
#include "UI.h"
#include <crtdbg.h>

int main()
{
	//testsProductRepo();
	//testController();
	//testsStack();
	ProductRepo* repo = createRepo();

	struct tm t1, t2, t3, t4;

	t1.tm_year = 2018;
	t1.tm_mon = 3;
	t1.tm_mday = 19;

	t2.tm_year = 2018;
	t2.tm_mon = 5;
	t2.tm_mday = 07;

	t3.tm_year = 2018;
	t3.tm_mon = 3;
	t3.tm_mday = 07;


	t4.tm_year = 2020;
	t4.tm_mon = 12;
	t4.tm_mday = 07;

	Product* p1 = createProduct("Milk", "dairy", 100, t1);

	Product* p2 = createProduct("Bread", "dairy", 200, t2);

	Product* p3 = createProduct("MilkyWay", "sweets", 150, t3);

	Product* p4 = createProduct("Chocolate", "sweets", 150, t3);

	addProduct(repo, p1);
	addProduct(repo, p2);
	addProduct(repo, p3);
	addProduct(repo, p4);
	destroyProduct(p1);
	destroyProduct(p2);
	destroyProduct(p3);
	destroyProduct(p4);

	Controller* ctrl = createController(repo);


	UI* ui = createUI(ctrl);
	//destroyController(ctrl);
	startUI(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}