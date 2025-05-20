#pragma once

/*
* STL(Standard Template Library) : 자료구조와 알고리즘을 쉽게 활용할 수 있도록 미리 구현된 코드 집합
* 
* -구성 요소-
* 1.컨테이너(Container) : 데이터를 저장하는 구조
*   - 순차 컨테이너(vector, list, deque)
*   - 연관 컨테이너(map, set, unordered_map)
*   - 컨테이너 어댑터(stack, queue, priority_queue)
* 2. 알고리즘(Algorithm) : 데이터를 처리하는 함수
*   - 정렬(sort, stable_sort)
*   - 검색(find, binary_search)
*   - 변환(transform, replace)
*   - 수학 연산(accumulate, inner_product)
* 3. 반복자(Iterator) : 컨테이너의 데이터를 탐색하는 도구
*   - 전진 반복자(forward_iterator)
*   - 양방향 반복자(bidirectional_iterator)
*   - 랜덤 접근 반복자(random_access_iterator -> vector에서 사용 가능)
* 
* 게임 개발에서 사용
* 
 컨테이너    (이름 충돌 방지를 위해 std::사용)
* 
* - std::vector(동적 배열) : 게임 오브젝트 관리 
*   ~ 게임 내 케릭터, 몬스터, 아이템 등을 저장하는데 많이 사용
    ~ 순차적인 데이터를 저장하고 빠르게 접근이 가능
    ~ 예) std::vector<GameObject> objects;

   - std::map(키-값 저장) : 맵 데이터, 설정값 저장
    ~ 게임 내 아이템 ID와 이름, 혹은 키 설정 같은 데이터를 저장할 때 사용
    ~ 키를 통해 빠르게 값을 찾을 수 있음
    ~ 예) std::map<int, std::string> itemNames;

  - std::set(중복 없는 데이터) : 유니크한 아이템 관리
    ~ 중복 없는 아이템을 저장하는데 사용
    ~ 중복 제거가 자동으로 되기 떄문에 아이템 목록을 관리하기가 용이
    ~ 예) set<string> collectedItems;

   - std::queue(선입선출 방식) : 이벤트 처리
    ~ 게임 이벤트(키 입력, 적 공격 등)를 처리하는데 용이
    ~ 선입선출(FIFO) 방식으로 정리하기 편리
    ~ 예) std::queue<GameEvent> eventQueue;

   - std::unorderde_map(해시 기반 맵) : 빠른 데이터 검색
    ~ NPC대사 저장, 아이템 속성 저장 등의 작업에 사용
    ~ 일반 std::map보다 빠르게 데이터 검색 가능
    ~ 예) std::unordered_map<std::string, int> npcDialogues;
 
 알고리즘
   
   - 정렬(std::sort, std::stable_sort)
    ~ 게임 내 점수판(Leaderboard)정렬, 아이템 목록 정렬 등에 사용
    ~ 빠른 정렬이 필요할 땐 std::sort, 기존 순서 유지가 필요할 땐 std::stable_sort

   - 탐색(std::find, std::binary_search)
    ~ 특정 오브젝트를 찾거나 인벤토리에 아이템이 있는지 확인할 때 사용
    ~ 정렬된 데이터에서는 std::binary_search가 더 빠름 ( (O(log n) )

   - 충돌 감지(Collision Detection)
    ~ 게임 캐릭터와 벽 또는 적과의 충돌을 감지할 때 활용
    ~ std::find 특정 값을 찾는데 사용
    ~ std::find_if 특정 조건을 만족하는 요소를 찾을 떄 많이 사용
                   충돌하는 객체를 찾거나 물리 엔진에서 AABB 또는 Raycasting적용

   - 경로 탐색(Pathfinding - A 알고리즘)
    ~ NPC가 장애물을 피해 길을 찾는 AI 시스템에서 사용
    ~ std::priority_queue 를 활용하여 최적의 경로 탐색 가능

   - 숫자 연산(std::accumulate, std::inner_product)
    ~ 점수 계산, 통계 분석 등에 사용
    ~ 모든 요소의 합을 구하거나, 백터 곱을 계산할 때 유용

반복자

   - 전진 반복자(std::forward_iterator)
    ~ 순차적으로 데이터를 탐색할 때 사용 (std::list, std::forward_list 등에 활용)
*/

