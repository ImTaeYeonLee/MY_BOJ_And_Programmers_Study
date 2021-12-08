#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 프로그래머스 키패드 누르기
int abs(int n)
{
	if(n < 0) return -n;
	else return n;
}

int distance(int pos, int dest)
{
	int dist = 0;

	dist += abs((pos - 1) / 3 - (dest - 1) / 3); // 행의 차이
	dist += abs((pos - 1) % 3 - (dest - 1) % 3); // 열의 차이

	return dist;
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";

	int left = 10, right = 12;

	for (int i = 0 ; i < numbers.size(); ++i)
	{
		int num = (numbers[i] != 0 ? numbers[i] : 11);

		if (num % 3 == 1)
		{
			left = num;
			answer.append("L");
		}
		else if (num % 3 == 0)
		{
			right = num;
			answer.append("R");
		}
		else
		{
			int left_dist = distance(left, num);
			int right_dist = distance(right, num);

			if (left_dist < right_dist)
			{
			left = num;
			answer.append("L");
			}
			else if (right_dist < left_dist)
			{
				right = num; // left에 num 값을 대입
				answer.append("R"); // answer에 L을 추가
			}
			else if (right_dist == left_dist) // 같다면
			{
				if (hand == "left")
				{
					left = num;
					answer.append("L");
				}
				else if (hand == "right")
				{
					right = num;
					answer.append("R");
				}
			}
		}
	}

	return answer;
}


/*
// BOJ 11052
int N;
int card[1001];
int DP[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> card[i];
	}

	DP[1] = card[1];

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			DP[i] = max(DP[i], DP[i-j]+card[j]);
		}
	}

	cout << DP[N];
}
*/
// 프로그래머스 로또의 최고 순위와 최저 순위//
/*
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int zero_cnt = 0, cnt = 0;
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) {
			zero_cnt++;
			continue;
		}
		for (int j = 0; j < win_nums.size(); j++) {
			if (lottos[i] == win_nums[j]) {
				cnt++;
				win_nums.erase(win_nums.begin()+j);
			}
		}
	}
	int maxi, mini;

	if(cnt<2)
	mini = 6;
	else
	mini = 6 - cnt + 1;

	if(zero_cnt + cnt < 2)
	maxi = 6;
	else
	maxi = 6 - (zero_cnt + cnt) + 1;

	answer.push_back(maxi);
	answer.push_back(mini);

	return answer;
}
*/

/*
// 전역변수 선언
int A, B;

int main()
{
	// 입력 받는다. 공백으로 구부난다
	while (cin >> A >> B)
	{
		if (A == 0 && B == 0)
		{
			break;
		}
		cout << A + B << "\n"; // 개행개행

	}
}
*/
/*수포자는 수학을 포기한 사람의 준말입니다.수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다.수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식 : 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식 : 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10, 000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
입출력 예
answers	return
[1, 2, 3, 4, 5][1]
[1, 3, 2, 4, 2][1, 2, 3]
입출력 예 설명
입출력 예 #1

수포자 1은 모든 문제를 맞혔습니다.
수포자 2는 모든 문제를 틀렸습니다.
수포자 3은 모든 문제를 틀렸습니다.
따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

모든 사람이 2문제씩을 맞췄습니다. */

/*
vector<int> solution(vector<int> answers) {
	vector<int> answer;

	//1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지, 배열에 담아 return 하도록 하자.
	// 완전탐색을 써야 한다.
	// algorithm 라이브러리의 max_element를 활용하여 max_value를 얻어와야 한다.

	return answer;
}
*/

//
//using namespace std;
///*새로 생긴 놀이기구는 인기가 매우 많아 줄이 끊이질 않습니다.이 놀이기구의 원래 이용료는 price원 인데, 놀이기구를 N 번 째 이용한다면 원래 이용료의 N배를 받기로 하였습니다.즉, 처음 이용료가 100이었다면 2번째에는 200, 3번째에는 300으로 요금이 인상됩니다.
//놀이기구를 count번 타게 되면 현재 자신이 가지고 있는 금액에서 얼마가 모자라는지를 return 하도록 solution 함수를 완성하세요.
//단, 금액이 부족하지 않으면 0을 return 하세요.
//
//제한사항
//놀이기구의 이용료 price : 1 ≤ price ≤ 2, 500, price는 자연수
//처음 가지고 있던 금액 money : 1 ≤ money ≤ 1, 000, 000, 000, money는 자연수
//놀이기구의 이용 횟수 count : 1 ≤ count ≤ 2, 500, count는 자연수
//입출력 예
//price	money	count	result
//3	20	4	10
//입출력 예 설명
//입출력 예 #1
//이용금액이 3인 놀이기구를 4번 타고 싶은 고객이 현재 가진 금액이 20이라면, 총 필요한 놀이기구의 이용 금액은 30 (= 3 + 6 + 9 + 12) 이 되어 10만큼 부족하므로 10을 return 합니다.*/
//
//long long solution(int price, int money, int count)
//{
//	long long answer = -1;
//	// 원래 이용료는 price원, count번째 이용료는 price원 * count 이다.
//	// count만큼 놀이기구를 타기 위해서는 account변수를 선언해서, account 값에 price원 * count를 계속 더해준다. for문 사용.
//	// 제한사항은 자연수, int 형식 사용
//
//	// 원래 가지고 있는 돈 money
//	// 놀이기구 탄 횟수 count
//	// 놀이기구 이용금액 price
//
//	// 놀이기구를 count번 타게 되면 얼마가 필요한지 account에 더해주자.
//	long long account = 0;
//	for (int i = 1; i <= count; i++)
//	{
//	account += price * i;
//	}
//	// 연산이 끝나면 원래 가지고 있던 금액 money에서 account를 빼주자.
//	if (money - account >= 0)
//	{
//		answer = 0;
//	}
//	else
//	{
//		answer = (money - account) * -1;
//	}
//	return answer;
//}


//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//int solution(int num) {
//
//	// 매개변수 int형 'num'의 경우, 626331을 계산 시 오버플로우가 발생하여
//	// long long형으로 자료형을 바꿔준다
//	long long n = num;
//
//	// 콜라츠 추측을 500번 반복하면서 1이 되면 반복횟수를 리턴해주는 동작
//	for (int i = 0; i < 500; i++) { // 500번 반복한다
//		if (n == 1) return i; // n이 1이라면 i를 리턴(반복한 횟수)
//		else if (n % 2 == 0) n /= 2; // 아니라면, 아래를 실행
//		else n = (n * 3) + 1;
//	}
//
//	return -1; // 500번을 반복하면 for문 종료되므로, for문 안에서 return하지 않고 for문에서 빠져나왔다면 -1을 리턴
//}
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr) {
//	vector<int> answer = arr;
//	int temp;
//
//	if (arr.size() == 1) {
//		answer.clear();
//		answer.push_back(-1);
//	}
//	else {
//		sort(arr.begin(), arr.end());
//
//		temp = arr.front();
//
//		for (int i = 0; answer.size(); i++) 
//			{
//			if(temp == answer[i])
//				{
//				answer.erase(answer.begin() + i);
//				break;
//				}
//			}
//	}
//	return answer;
//} 

//#include <string>
//#include <vector>
//
//// 프로그래머스 하샤드 수
//using namespace std;
//
//bool solution(int x) {
//// x 를 입력받아 x가 하샤드 수인지(각 자릿수의 합으로 자기 자신을 나누었을 때, 나머지가 0이면 하샤드 수이므로 true를 반환) 
//	bool answer = true;
//
//	// x를 orizin_x 저장하고, 각 자릿수의 합을 저장할 div 변수 선언
//		int div = 0, orizin_x = x;
//	// i의 초기값 10, i가 100000보다 작다면, 아래를 실행하고 i를 i * 10한 값으로 정의
//		while (x > 0) { // int형이므로 x가 1보다 작은 소숫점으로 내려가면 while문이 끝나는 것 같습니다. 정확히 아시는 고수님 계시면 가르침 부탁드립니다...
//			div += x % 10; // div값을 자기 자신 + x % 10(나머지) 으로 재 정의
//			x = x / 10; // x값을 x를 10으로 나눈 값으로 재 정의
//	}
//	
//	// orizin_x를 각 자릿수를 더한 div값으로 나눈 나머지 % 를 구해서, 0이면 true, 아니라면 false를 리턴하자.
//
//	if(orizin_x % div == 0)
//		answer =  true;
//	else
//		answer =  false;
//	return answer;
//}

//// 프로그래머스 행렬의 덧셈(이중 벡터)
//using namespace std;
//
//vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
//// 반환자료형이 vector인 solution 함수 선언, vector 2개를 인자로 받는다.
//	vector<vector<int>> answer; // solution함수가 반환할 값 answer 선언
//	vector<int> temp; // 값을 먼저 계산해서 넣을 temp벡터를 선언
//	for (int i = 0; i < arr1.size(); i++) { // arr1과 arr2의 크기는 같을 것이므로 arr1의 크기만큼 아래를 for문 돌린다.
//		temp.clear(); // temp 벡터의 값을 지움
//		for (int j = 0; j < arr1[i].size(); j++) { // 1번만 실행
//			temp.push_back(arr1[i][j] + arr2[i][j]); // temp 벡터에 행렬의 값을 더한 값을 넣는다. 앞쪽이 이미 채워져 있다면 빈 곳부터 넣어준다(넣을대상벡터.push_back(넣을값))
//		}
//		answer.push_back(temp); // answer 벡터에 temp 벡터의 값을 뒤에 하나씩 넣는다
//	}
//	return answer;
//}

//using namespace std;
//
//// BOJ 10814
//// 키(기준)으로 사용한 나이가 중복될 수 있으므로 map이 아닌 여러 키를 가질 수 있는 multimap을 사용하였다!
//// 첫째 줄에 온라인 저지 회원의 수 N이 주어진다.
//// 둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다.
//// 입력은 가입한 순서대로 주어진다.
//
//int main()
//{
//	multimap<int, string> m;// int, string을 매개변수로 받는 클래스(변수&함수) muiltimap을 사용한다. multimap타입의 변수 m을 선언, 인스턴스 변수는 int와 string
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		string s;
//
//		cin >> x;
//		cin >> s; // 이렇게 쓰면 공백으로 구분하여 x와 s를 입력받는다. 엔터로도 구분되는데 공백으로도 구분됨!
//
//		m.insert(pair<int, string>(x,s)); // multimap m의 인스턴스메소드(멤버 함수) insert를 실행한다. 
//	}
//
//	for (pair<int, string> data : m)
//	{
//		cout << data.first << ' ' << data.second << '\n';
//	}
//}


//// BOK 11651
//// 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서대로 정렬한 다음, 출력한다.
//// a와 b의 값을 비교하여, 정렬 후, 출력한다.
//bool comp(pair<int, int> a, pair<int, int> b)
//{
//	if(a.second < b.second)
//		return true;
//	else if(a.second == b.second)
//	{
//		if(a.first < b.first)
//			return true;
//	}
//
//	return false;
//}
//
//int main()
//{
//	int n;
//	vector<pair<int, int>> vec;
//
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		int x, y;
//		cin >> x >> y;
//		vec.push_back(make_pair(x,y));
//	}
//
//	sort(vec.begin(), vec.end(), comp);
//	for (int i = 0; i < n; ++i)
//	{
//		cout << vec[i].first << ' ' << vec[i].second << '\n';
//	}
//}

//// BOJ 11650
//
//bool compare(pair<int, int> a, pair<int, int> b) // 원소를 서로 비교한 결과를 t/f로 나타낼 compare 함수. sort의 기준 설정으로 쓰일 것이다.
//{
//	if(a.first == b.first) // a와 b의 첫번째 원소(x)의 값이 같다면
//		return a.second < b.second; // a와 b의 두번째 원소(y)를 비교해서 b의 원소가 더 크다면 true를 리턴
//
//	return a.first < b.first; // a와 b의 첫번째 원소(x) 를 비교해서 b가 더 크면 true를 리턴
//}
//
//int main()
//{
//	vector<pair<int, int>> vec; // pair 구조체가 자료형인, 벡터 vec을 선언
//
//	int n;
//	int x, y;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) // n번만큼 반복
//	{
//		cin >> x;
//		cin >> y; // x와 y를 엔터키로 구분하여 입력받는다.
//
//		vec.push_back(make_pair(x,y)); // 구조체 인스턴스 pair은 int 2개를 매개변수로 갖는다. pair을 만들되, 매개변수는 x, y로 설정하고, vec의 뒤 index에 넣어준다
//	}
//
//	sort(vec.begin(), vec.end(), compare); // compare는 정렬의 기준 설정. 맨 위에 만들어 놓은 compare()함수의 반환 값에 맞게 정렬이 동작한다. 아무것도 넣지 않았다면 기본이 오름차순이기 때문에 오름차순으로 정렬될 것이다.
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << vec[ i ].first << ' ' << vec[ i ].second << '\n'; // 정렬이 끝났으니, vec의 i번째 인덱스의 (pair의)첫번째 인자(x)와 두번째 인자(y)를 출력한다.
//	}
//
//}

// BOJ 2751
// 2751번은 quickSort를 사용해도 시간초과가 발생합니다.따라서 MergeSort를 통해 문제를 풀었습니다.
// MergeSort는 최악의 경우에도 O(nlogn)인 반면에 quickSort는 평균적으로 O(nlogn)이지만 최악일 때는 O(n ^ 2)
//const int MAX = 1000000;
//
//int N;
//int arr[MAX];
//int tempArr[MAX];
//
//void merge(int low, int mid, int high) {
//	int i = low, j = mid + 1, k = low;
//
//	while (i <= mid && j <= high) {
//		if(arr[i] < arr[j])
//		tempArr[k] = arr[i++];
//		else
//		tempArr[k] = arr[j++];
//		k++;
//	}
//
//	if( i > mid)
//	for(int idx = j ; idx <= high ; idx++)
//	tempArr[k++] = arr[idx];
//	else
//	for(int idx = i ; idx <= mid ; idx++)
//	tempArr[k++] = arr[idx];
//
//	for(int idx = low ; idx <= high; idx++)
//	arr[idx] = tempArr[idx];
//}
//
//void mergeSort(int low, int high)
//{
//	if (high > low)
//	{
//		int mid = (low + high) / 2;
//		mergeSort(low, mid);
//		mergeSort(mid + 1, high);
//		merge(low, mid, high);
//	}
//}
//
//int main(void) 
//{
//cin >> N;
//
//for(int i = 0 ; i < N ; i++)
//{
//scanf("%d", &arr[i]);
//}
//
//mergeSort(0, N - 1);
//
//for(int i = 0 ; i < N ; i++)
//{
//printf("%d\n", arr[i]);
//}
//
//return 0;
//}



// BOJ 2750
//int main() {
//int arr[1000001]; // 크기가 1,000,000 보다 큰 배열 선언 1,000,001인 배열
//int N; // 입력받은 값을 저장할 변수 N 선언
//cin >> N; // N 입력받기
//
//for(int i = 0 ; i < N ; i++) // 입력받을 때마다 arr의 i번째 인덱스에 값 넣기. N번만큼 반복 
//cin >> arr[i];
//
//sort(arr, arr+N); // 오름차 정렬. arr의 첫번째 인덱스부터 arr의 N번째 인덱스(미포함)까지
//
//for(int i = 0 ; i < N ; i++) // 오름차 정렬된 arr의 i번째 인덱스 값을 cout한다. 0부터 N번만큼 반복
//cout << arr[i] << "\n";
//
//}




// 프로그래머스 타겟 넘버 C++
//n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다섯 방법을 쓸 수 있습니다.
// 사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성하자.
// numbers, target, return 이 주어진다.
// numbers 안에 있는 모든 숫자를 한 번씩 이용해서 target의 숫자를 만드는 문제이다.
// dfs 와 간단한 재귀로 완성할 수 있다.
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int answer = 0;
//int target_num;
//
//void dfs(int count, int current_target, vector<int>& numbers) {
//	if (count == numbers.size()) {
//		if(current_target==target_num)
//		answer++;
//		return;
//	}
//
//	int next_target1 = current_target + numbers[count];
//	int next_target2 = current_target - numbers[count];
//
//	dfs(count + 1, next_target1, numbers);
//	dfs(count + 1, next_target2, numbers);
//}
//
//int solution(vector<int> numbers, int target) {
//	target_num = target;
//	dfs(0,0,numbers);
//	return answer;
//}


/*
// 프로그래머스 네트워크 C++
// computers[i][j] == 0 이면 i 컴퓨터가 j 컴퓨터와 연결이 되어 있다는 것
// 컴퓨터가 총 3대면,
// i 는 총 0, 1, 2
// j 는 총 0, 1, 2 각각의 컴퓨터에서 자기 자신을 포함한 컴퓨터들에 대한 연결을 나타낸 게 computers다.
// 깊이 우선 탐색 DFS

#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visited[200];

void dfs(int start, int n, vector<vector<int>>& computers) {
	visited[start]=true;
	for (int i = 0; i < computers[start].size(); i++) {
		if (i != start && !visited[i] && computers[start][i]) {

		dfs(i, n, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < computers.size(); i++) {
		if (!visited[i]) {
			cout << i << "\n";

			dfs(i, n, computers);
			answer++;
		}
	}
	dfs(0, n, computers);
	return answer;
}
*/

// BOJ 10818
// 입출력과 알고리즘 익히기
// 야 힘내
// 더 좋은 날들이 내일 속에서 널 기다리고 있어
// 오늘도 시작해 줘서 고마워!
/*
#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char* argv[])
{
	ios_base::sync_with_stdio(false);

	// 배열의 요소를 공백으로 구분하여 입력받자
	// sort 함수를 쓸것이다. 문법은 sort(배열의 시작 주소, 배열의 마지막 주소)sort(array + 0, array + N)
	// sort는 시작주소(포함) ~ 끝 주소(미포함) 범위를 오름차순으로 정렬해주는 형식이다.
	// 보통은 N개의 크기를 갖고 있는 배열에 대해, 전체를 정렬하는 경우 더 간단하게
	// sort(array, array + N) 이런 식으로 쓰긴 하지만,
	// 만약 일정 부분만 정렬하고 싶다면 array에 수를 더해서 시작 주소 혹은 끝 주소를 설정할 수도 있다.

	int N; // 정수의 갯수 N
	cin >> N; // 정수의 갯수 입력받고

	int array[N]; // a

	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}

	sort(array, array + N); // 0 ~ N - 1까지의 범위를 오름차순으로 정렬한다.

	cout << array[0] << " " << array[N - 1];
}

*/
//int main()
//{
//	int n;
//	cin >> n;
//	// 1 부터 n 까지 합을 출력한다.
//	// for 문으로 1 부터 n 까지 합을 구하려면
//	// n 을 1씩 빼면서
//	// for문 밖에 선언한 새로운 변수 result 에 값을 더해주면 될 것 같다.
//	
//	int result(0);
//
//	for (int i = 0; i < n; n--)
//	{
//		result += n; // 자기 자신에 n을 더한다는 것은 += n 이라고 쓴다. 
//	}
//	cout << result;
//}
//{
//	int x = 0;
//	int y = 0;
//	int sum = 0;
//	int dayInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	// 8 일도 월요일이므로, 0번째 인덱스에 일요일을, 1번째 인덱스에 월요일을 넣자.
//	const char* day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
//
//	cin >> x >> y;
//	for (int i = 1; i < x; i++) // for 문으로 입력받은 x의 값만큼 반복해 더한다
//	{
//		sum += dayInMonth[i - 1]; // sum 에는 dayInMonth의 0번째 인덱스의 값부터 더해진다.
//		// -1 해서 원하는 인덱스까지만 더해지게 해 주자.
//	}
//	sum += y; // 월을 구했으니 일을 더해준다 x월의 y일이므로, y만큼을 더 더한다.
//	cout << day[sum % 7] << "\n"; // 7로 나누었을 때 1이 남으면 일요일, 2가 남으면 월요일...
//	// day 배열의 sum % 7 번째 인덱스의 요소를 출력한 것.
//
//}
//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	// 2007년 1월 1일은 월요일이다
//	// x, y를 입력받아, x는 월이고 y는 일이라고 할 때,
//	// x월 y일이 무슨 요일인지 구하시오.
//	int x = 0; 
//	int y = 0;
//	int result;
//
//	int month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	// 8 일도 월요일이므로, 0번째 인덱스에 일요일을, 1번째 인덱스에 월요일을 넣자.
//	const char* date[] = { "일", "월", "화", "수", "목", "금", "토" };
//
//	cin >> x >> y;
//	
//	for (int i = 0; i < x; i++)
//	{
//		result += month[i - 1];
//	}
//	// 월을 구했으니 일을 더해준다
//	result =+ y;
//	cout << date[result % 7] << "\n";
//
//
//
//}

	//long long int ss[3] = {0};
	//cout << sizeof(ss) << "\n"; // long long 은 8byte를 차지하므로 8을 return
	//cout << sizeof(&ss) << "\n"; // 배열의 시작 주소 4
	//
	//char s[] = {1,2,3,4,5,0};
	//cout << sizeof(s) << "\n"; // 메모리 공간을 차지하는 byte 수인 6을 return
	//cout << size(s)<<"\n"; // 주어진 컨테이너 혹은 배열의 사이즈인 6을 return
	//cout << sizeof(&s) << "\n"; // 배열의 이름은 배열의 시작주소를 의미한다.
	//
	//// sizeof(배열이름)은 4byte 혹은 8byte 가 return.




	//// 첫째 줄에 단어 N이 주어진다.
	//string N;
	//getline(cin, N); // getline 으로 1줄을 입력받는다.

	//// 입력으로 주어진 단어를 열 개씩 끊어서 한 줄에 하나씩 출력하고 싶다.
	//for (int i = 0; i < N.size() ; i++)
	//{
	//	// 입력받은 글자 수만큼 반복하여 출력하면서
	//	cout << N[i];
	//	// 만약 10으로 나눠 떨어진다면 줄바꿈을 한다.
	//	if ((i + 1) % 10 == 0) 
	//		// 0부터 시작했으니 +1 해 준다.
	//		// 0~9 까지는 줄바꿈하지 않고, 10번째에는 10으로 나누어떨어지므로 줄바꿈을 하게 된다.
	//		// 이 과정을 11 ~ N 까지 반복한다.
	//	{
	//		cout << "\n";
	//	}
	//}

//int main()
//{
//	string n;
//	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//	//while(cin >> n)
//	while (getline(cin, n)) // 공백을 포함해서 입력받을 것이므로 getline(문자들을 읽어들일 스트림, 입력할 문자를 저장할 문자열, 구분 문자(여기서는 생략))을 쓰자!
//	{
//		cout << n;
//		cout << "\n";
//	}
//}
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main(void)
//{
//	int t = 0; // 테스트 케이스 초기화
//	cin >> t; // 테스트 케이스 입력받기
//
//	string *testCase = new string[t]; // string 자료형의 testCase 는 new 매크로를 사용해서 만들어 낸 string 자료형의 배열이다.
//	// new 매크로를 사용해서 새로 string 클래스 하나를 만들 것이다.
//	// string을 설계도로 가지는 포인터 변수 testCase 가 선언되었다.
//	// 이 testCase의 주소는 힙에 올라가 있다.
//	int *deleteComma = new int[t];
//	// new 매크로를 사용하여 int 타입의 deltaComma 포인트변수를 선언
//	// 이 포인터변수 배열 크기는 t만큼의 인덱스를 가진다
//	// 이 포인터변수의 주소는 힙에 올라가 있다. 메모리 누수를 방지하기 위해
//	// 함수의 마지막 줄에 delete[] deleteComma; 를 써주장!
//	// delete deleteComma 가 아닌, delete[] deleteComma 해 주는 이유는 배열로 선언되었기 때문이다.
//	// https://docs.microsoft.com/ko-kr/cpp/code-quality/c6278?f1url=%3FappId%3DDev16IDEF1%26l%3DKO-KR%26k%3Dk(C6278)%26rd%3Dtrue&view=msvc-160
//
//	for (int i = 0; i < t; i++) // t 번만큼 아래를 반복
//	{
//		cin >> testCase[i]; // testCase에 값을 넣고,
//		testCase[i].erase(1, 1); // erage 함수를 이용해 Comma 를 삭제한다
//		deleteComma[i] = stoi(testCase[i]); // stoi 함수를 이용해 string으로 입력받은 값을 int로 변환해 deleteComma에 넣어준다.
//	}
//
//	for (int i = 0; i < t; i++)
//	{
//		cout << deleteComma[i] % 10 + (deleteComma[i] - (deleteComma[i] % 10)) / 10 << "\n";
//		// 1. deleteComma[i] 를 10으로 나눈 것의 나머지 = deleteComma[i] 의 요소의 1의 자리
//		// 2-1. (deleteComma[i] - (deleteComma[i] % 10)) = deleteComma[i] 의 요소의 10의 자리 
//		// 2-2. 위 값을 / 10 = 하면 deleteComma[i] 의 10의 자리 수가 나온다.
//		// 1과 2-2 를 더하면, 1의 자리와 10의 자리를 더한 값이 된다.
//	}
//
//	delete[] testCase;
//	delete[] deleteComma;
//}


// ---------------입출력 연습---------------------
//#include <iostream>
//
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cout << "Hello World!" << "\n";
//}
//#include "pch.h"
//#include <iostream>
//
//#define endl "\n"
//#define MAX 1001 // 수열 A의 크기 N( 1 <= N <= 1000 )
//using namespace std;
//
//int N; // 전역변수 선언 N, Arr, DP
//int Arr[MAX];
//int DP[MAX];
//
//void Input()
//{
//	cin >> N; // 수열 A의 크기 N을 입력받는다
//	for (int i = 1; i <= N; i++) // 수열 A를 이루고 있는 Ai 이므로, 앞서 입력받은 N번만큼 입력받으면 된다. for문으로 반복해서 입력받는 것을 처리하자.
//	{
//		cin >> Arr[i]; // Arr의 i번째에서부터 차례대로 입력받아서 값을 넣어준다.
//	}
//}
//
//void Solution()
//{
//	// 2가지 조건을 충족하면서 길이를 갱신해 준다.
//	// 1. 더 작은 인덱스 값이 현재 인덱스의 값보다 더 큰가?
//	// 2. 현재 비교하고 있는 이 인덱스의 값을 선택하는 것이, 최대길이가 될 수 있는가?
//	
//	// 수열 N 은 N 개의 요소를 가질 것이므로, 1부터 N 까지 아래 내용을 반복한다. 
//	for (int i = 1; i <= N; i++)
//	{
//		// 만약 수열 A{1, 6, 5, 7, 2, 4} 일 때, 
//		
//		DP[i] = 1; // DP의 i번째 인덱스의 요소 값을 초기화
//
//		for (int j = 1; j <= i; j++) // 비교할 인덱스 번호인 j를 정의해준다.
//		{
//			// 위에서 정의한 조건에 맞다면,
//			// DP[i] = DP[j] + 1 번째 요소의 값으로 재 정의해준다.
//			if (Arr[i] < Arr[j] && DP[j] + 1 > DP[i])
//			{
//				// 1. 더 작은 인덱스 값 j( j <= i 로 조건을 줬으므로, i보다 작은 인덱스들을 전부 비교하고, i번째 인덱스와도 비교할 것이다.) 가 현재 인덱스 값 i보다 큰가?
//				// 2. j + 1 번째 인덱스의 값이, i 번째 인덱스의 값보다 큰가?
//				DP[i] = DP[j] + 1;
//			}
//		}
//	}
//
//	int Max = 0; // 변수 Max 를 선언하고 초기화합니다.
//	// N 번만큼 for문을 돌려서 아래를 검사합니다.
//	for (int i = 1; i <= N; i++)
//	{
//		// Max 의 값은 0으로 정의했습니다. 만약 DP[i]번째 인덱스의 값이 Max 의 값 보다 크다면 
//		if (DP[i] > Max)
//		{
//			// Max 의 값을 DP[i] 번째 인덱스의 값으로 재 정의해줍니다.
//			Max = DP[i];
//		}
//	}
//	// Max 의 값을 출력합니다. 
//	cout << Max << endl;
//}
//
//void Solve()
//{
//	Input();
//	Solution();
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	Solve();
//
//	return 0;
//}

//#include "pch.h"
//#include <iostream>
//
//#define endl "\n"
//#define MAX 1001
//using namespace std;
//
//int N;
//int Arr[MAX];
//int DP[MAX];
//
//void Input()
//{
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> Arr[i];
//	}
//}
//
//void Solution()
//{
//	for (int i = 1; i <= N; i++)
//	{
//		DP[i] = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			if (Arr[i] < Arr[j] && DP[j] + 1 > DP[i])
//			{
//				DP[i] = DP[j] + 1;
//			}
//		}
//	}
//
//	int Max = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		if (DP[i] > Max)
//		{
//			Max = DP[i];
//		}
//	}
//	cout << Max << endl;
//}
//
//void Solve()
//{
//	Input();
//	Solution();
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	Solve();
//
//	return 0;
//}




//// https://velog.io/@redgem92/C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-Level-2-%EC%98%A4%ED%94%88%EC%B1%84%ED%8C%85%EB%B0%A9 참고한 블로그
//#include <iostream>
//#include <string>
//#include <vector> // https://life-with-coding.tistory.com/411 vector 기본 사용법 및 예제 활용
//#include <algorithm>
//#include <map>
//
//#include <sstream> // ★ 알아볼 거
//
//using namespace std;
//
//namespace {
//    // 단어는 공백으로 구분되어 있으니까 문자열을 구분자로 나눈 문자열의 집합을 먼저 구한다.
//    // 함수를 써서 구한다.
//    vector<string> Split(string input, char delimiter) // vector<변수 타입> 벡터이름(크기, 초기화 상수)
//    {
//        vector<string> ret; // string 타입을 저장하는 ret 벡터를 생성
//        stringstream ss(input); // sstream 헤더에 포함된 클래스인가?
//        string tmp; // string 타입의 데이터를 저장하는 tmp 변수를 생성
//
//        while (getline(ss, tmp, delimiter)) // 
//            // 입력 방식 중에 공백문자를 스트림에 남겨놓는 입력방식 뒤에 getline을 바로 호출하게 된다면, getline은 해당 공백문자를 읽고 바로 읽기를 종료하게 된다.
//            // 공백문자란 개행문자, 띄어쓰기와 같은 눈에 보이지 않는 문자들을 의미한다. 이 문자들은 흔히 delimiter로 사용된다.
//            // https://modoocode.com/236
//            // 입력 스트림에서 문자를 읽어서, 인자로 받은 문자열에 저장한다. delim 문자를 읽게 되면 해당 문자를 버리고 읽어들이기를 종료한다. 만약 delim 문자를 설정하지 않았다면 디폴트로 개행 문자('\n')로 설정된다.
//            ret.push_back(tmp); // ret 벡터의 맨 뒤 index에 저장한다 tmp값을
//        // push_back() 함수는 맨 뒤에 원소를 추가한다. tmp는 인덱스가 몇 개인지 정해주지 않아서 첫 번째 인덱스부터 하나하나 추가되게 될 것이다.
//        // https://2018-start.tistory.com/82
//        return ret;
//    }
//
//    // 문자열을 분석해서 이후 답을 구하기 위한 자료구조를 구성하고 초기화한다.
//    enum ActionType
//    {
//        NONE = 0,
//        ENTER,
//        LEAVE,
//        CHANGE,
//    };
//
//    void ParseRecord(string record, ActionType& actionType, string& uid, string& nickName)
//    {
//        const vector<string>& parsed = Split(record, ' ');
//
//        if (parsed[0] == "Enter")
//        {
//            actionType = ENTER;
//            uid = parsed[1];
//            nickName = parsed[2];
//        }
//        else if (parsed[0] == "Leave")
//        {
//            actionType = LEAVE;
//            uid = parsed[1];
//        }
//        else if (parsed[0] == "Change")
//        {
//            actionType = CHANGE;
//            uid = parsed[1];
//            nickName = parsed[2];
//        }
//    }
//}
//
//vector<string> solution(vector<string> records)
//{
//    map<string /* UID */, string /* NickName */> idMap;
//    vector<pair<string /* UID */, ActionType/* Enter/Leave */>> records2;
//    for (const string& record : records)
//    {
//        ActionType actionType = NONE;
//        string uid, nickName;
//        ParseRecord(record, actionType, uid, nickName);
//        if (actionType == NONE)
//            continue;
//
//        switch (actionType)
//        {
//        case ENTER:
//        {
//            idMap[uid] = nickName;
//            records2.push_back(make_pair(uid, ENTER));
//        } break;
//        case LEAVE:
//        {
//            records2.push_back(make_pair(uid, LEAVE));
//        } break;
//        case CHANGE:
//        {
//            idMap[uid] = nickName;
//        } break;
//        }
//    }
//
//    vector<string> answer;
//    for (const pair<string, ActionType>& record : records2)
//    {
//        string res = idMap[record.first] + "님이 ";
//        res += (record.second == ENTER) ? "들어왔습니다." : "나갔습니다.";
//
//        answer.push_back(res);
//    }
//
//    return answer;

//#include <iostream>
//
//#define endl "\n"
//#define MAX 1001
//using namespace std;
//
//int N;
//int Arr[MAX];
//int DP[MAX];
//
//void Input()
//{
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> Arr[i];
//	}
//}
//
//void Solution()
//{
//	int Max = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		DP[i] = Arr[i];
//		for (int j = 1; j < i; j++)
//		{
//			if (Arr[j] < Arr[i] && DP[i] < DP[j] + Arr[i])
//			{
//				DP[i] = DP[j] + Arr[i];
//			}
//		}
//		if (Max < DP[i]) Max = DP[i];
//	}
//	cout << Max << endl;
//}
//
//void Solve()
//{
//	Input();
//	Solution();
//}
//
//int main(void) {
//	// 가장 큰 조건은 증가하는 부분 수열이어야 한다는 것이다
//	// 부분 수열의 각 원소들의 합이 최대가 되는 부분 수열을 찾아야 한다
//	// 2가지 배열을 사용한다.
//	// 1. 입력으로 주어지는 수열을 저장하는 Arr[]
//	// 2. 최댓값을 저장하는 배열 DP[]
//	// DP[a] = b 의 의미는 "a번 인덱스 까지의 가장 큰 부분 수열의 합은 b 입니다" 이다.
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	Solve();
//
//	return 0;
//}



//#include <string>
//#include <regex> // 정규 표현식 regex를 사용하자
//
//using namespace std;
//
//// 정규 표현식 regex_replace를 사용해서 원하는 패턴의 문자열을 다른 문자열으로 치환할 것이다.
//int solution(string s) {
//	regex_replace(s, regex("zero"), "0"); // regex_replace의 인자값은
//	// 1. 치환하고자 하는 문자열 2. 정규 표현식 객체  3. 어떤 형태로 치환할 것인지
//	// 1. 치환하고자 하는 문자열 s 가 첫번째 인자값
//	// 2. 정규 표현식 객체 regex("zero") 가 두번째 인자값
//	// 3. zero를 0으로 치환하고 싶으므로 0의 형태로 치환하겠다는 뜻인 0이 3번째 인자값
//	s = regex_replace(s, regex("one"), "1");
//	regex_replace(s, regex("two"), "2");
//	regex_replace(s, regex("three"), "3");
//	regex_replace(s, regex("four"), "4");
//	regex_replace(s, regex("five"), "5");
//	regex_replace(s, regex("six"), "6");
//	regex_replace(s, regex("seven"), "7");
//	regex_replace(s, regex("eight"), "8");
//	regex_replace(s, regex("nine"), "9");
//	return stoi(s); //  stoi 는 string 문자열을 숫자로 바꾸어주는 함수다. <string> 헤더 파일에 포함되어 있다.
//	// return 값을 담는 변수의 이름이 꼭 answer일 필요는 없다.
//}

//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 1000;
//int arr[MAXN + 1], dp[MAXN + 1] = { 0, }; // 모든 원소를 0으로 초기화
//
//int bottomUp(int n) {
//	for (int i = 1; i <= n; i++) {
//	scanf("%d", & arr[i]);
//	}
//
//	int ans;
//	for (int i = 1; i <= n; i++) {
//		int curr = 0;
//		for (int j = 1; j < i; j++) {
//			if (arr[i] > arr[j])
//				curr = max(curr, dp[j]);
//		}
//		dp[i] = curr + 1;
//		ans = max(ans, dp[i]);
//	}
//	return ans;
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", bottomUp(n));
//	return 0;
//}











//#include "pch.h"
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 10000;
//
//int P[MAXN + 1] = { 0, };
//int dp[MAXN + 1] = { 0, };
//
//int max(int a, int b, int c) { return a > b ? (a > c) ? a : c : (b > c) ? b : c; }
//
//int bottomUp(int n) {
//    dp[0] = P[0];
//    dp[1] = P[0] + P[1];
//
//    for (int i = 2; i < n; i++) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + P[i], dp[i - 3] + P[i] + P[i - 1]);
//    }
//    return dp[n - 1];
//}
//
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//
//    for(int i = 0 ; i < n ; i++)
//    {
//        scanf("%d", &P[i]);
//    }
//    printf("%d\n", bottomUp(n));
//
//    return 0;
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
