#include <iostream>
#include "BoxCollider.h"
#include "CircleCollider.h"

using namespace std;




int main()
{
	Collider *listCollider[2];
	BoxCollider *n1 = new BoxCollider(Vector3(1, 1, 1) , 2, 2, 2);
	CircleCollider *c1 = new CircleCollider(Vector3(3.0, 0.5, 0.5), 1);
	listCollider[0] = n1;
	listCollider[1] = c1;



	cout << "" << listCollider[0]->IsCollsion(*listCollider[1]);


	
	vector<Vector3> der = c1->GetPointsToCheck();
	system("pause");
	return 0;
}