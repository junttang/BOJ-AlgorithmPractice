#include <iostream>
#include <string>
// Algospot - QUADTREE
using namespace std;

// x (xwwwb)(xw(xwbbb)ww)(x(x(xwwbb)bww)wwb)b
// xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

string image;
int index;

typedef struct _node{	// 쿼드 트리를 구축하기 위한 기본 구조체
	char data;
	struct _node *upleft;	// NODE라는 명칭은 link 설정 시점 이후에 정의되기에
	struct _node *upright;	// struct _node로 변수를 정의해야함에 주의!
	struct _node *downleft;
	struct _node *downright;
}NODE;

NODE* makeTree(void) {		// 쿼드트리를 구축하는 함수
	NODE *newNode = new NODE;		// 호출 시마다 NODE 할당

	if (index >= image.size())		// index 변수는 image라는 스트링을 매 호출마다
		return NULL;			// 조회하는 변수로, 호출시마다 1씩 increment된다.
	// 따라서 index가 image 스트링의 마지막 인덱스보다 큰 경우엔 함수는 널을 반환한다.
	newNode->data = image[index];
	index++;

	if (newNode->data == 'x') {		// 문제 상황에 따라 x인 경우엔 아래와 같이 재귀적
		newNode->downleft = makeTree();		// 으로 4개의 자식노드를 연결한다.
		newNode->downright = makeTree();	// 인덱스 변수의 도입은 바로 이 부분에서
		newNode->upleft = makeTree();		// 스트링의 각 요소를 이 흐름에 맞게 접근
		newNode->upright = makeTree();		// 하기 위함이다.
		// 이때, 상하를 뒤집기 위해 down링크부터 연결하고 있음을 주목
	}
	else {	// x가 아닌 경우엔 말단노드이므로
		newNode->upleft = newNode->upright
			= newNode->downleft = newNode->downright = NULL;
	}

	return newNode;
}

void readTree(NODE *node) {	// 문제 상황과 쿼드 트리의 구조 고려 시 전위순회가 올바름.
	if (node != NULL) {
		cout << node->data;
		readTree(node->upleft);
		readTree(node->upright);
		readTree(node->downleft);
		readTree(node->downright);
	}
}

int main(void) {
	int C;

	cin >> C;
	while (C--) {
		cin >> image;

		index = 0;
		NODE* root = makeTree();
		readTree(root);
		cout << endl;
		
		image.clear();	// 각 테스트 케이스마다 초기화해주는 것 중요
	}

	return 0;
}