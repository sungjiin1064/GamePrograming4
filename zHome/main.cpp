#pragma once

/*
* STL(Standard Template Library) : �ڷᱸ���� �˰����� ���� Ȱ���� �� �ֵ��� �̸� ������ �ڵ� ����
* 
* -���� ���-
* 1.�����̳�(Container) : �����͸� �����ϴ� ����
*   - ���� �����̳�(vector, list, deque)
*   - ���� �����̳�(map, set, unordered_map)
*   - �����̳� �����(stack, queue, priority_queue)
* 2. �˰���(Algorithm) : �����͸� ó���ϴ� �Լ�
*   - ����(sort, stable_sort)
*   - �˻�(find, binary_search)
*   - ��ȯ(transform, replace)
*   - ���� ����(accumulate, inner_product)
* 3. �ݺ���(Iterator) : �����̳��� �����͸� Ž���ϴ� ����
*   - ���� �ݺ���(forward_iterator)
*   - ����� �ݺ���(bidirectional_iterator)
*   - ���� ���� �ݺ���(random_access_iterator -> vector���� ��� ����)
* 
* ���� ���߿��� ���
* 
 �����̳�    (�̸� �浹 ������ ���� std::���)
* 
* - std::vector(���� �迭) : ���� ������Ʈ ���� 
*   ~ ���� �� �ɸ���, ����, ������ ���� �����ϴµ� ���� ���
    ~ �������� �����͸� �����ϰ� ������ ������ ����
    ~ ��) std::vector<GameObject> objects;

   - std::map(Ű-�� ����) : �� ������, ������ ����
    ~ ���� �� ������ ID�� �̸�, Ȥ�� Ű ���� ���� �����͸� ������ �� ���
    ~ Ű�� ���� ������ ���� ã�� �� ����
    ~ ��) std::map<int, std::string> itemNames;

  - std::set(�ߺ� ���� ������) : ����ũ�� ������ ����
    ~ �ߺ� ���� �������� �����ϴµ� ���
    ~ �ߺ� ���Ű� �ڵ����� �Ǳ� ������ ������ ����� �����ϱⰡ ����
    ~ ��) set<string> collectedItems;

   - std::queue(���Լ��� ���) : �̺�Ʈ ó��
    ~ ���� �̺�Ʈ(Ű �Է�, �� ���� ��)�� ó���ϴµ� ����
    ~ ���Լ���(FIFO) ������� �����ϱ� ��
    ~ ��) std::queue<GameEvent> eventQueue;

   - std::unorderde_map(�ؽ� ��� ��) : ���� ������ �˻�
    ~ NPC��� ����, ������ �Ӽ� ���� ���� �۾��� ���
    ~ �Ϲ� std::map���� ������ ������ �˻� ����
    ~ ��) std::unordered_map<std::string, int> npcDialogues;
 
 �˰���
   
   - ����(std::sort, std::stable_sort)
    ~ ���� �� ������(Leaderboard)����, ������ ��� ���� � ���
    ~ ���� ������ �ʿ��� �� std::sort, ���� ���� ������ �ʿ��� �� std::stable_sort

   - Ž��(std::find, std::binary_search)
    ~ Ư�� ������Ʈ�� ã�ų� �κ��丮�� �������� �ִ��� Ȯ���� �� ���
    ~ ���ĵ� �����Ϳ����� std::binary_search�� �� ���� ( (O(log n) )

   - �浹 ����(Collision Detection)
    ~ ���� ĳ���Ϳ� �� �Ǵ� ������ �浹�� ������ �� Ȱ��
    ~ std::find Ư�� ���� ã�µ� ���
    ~ std::find_if Ư�� ������ �����ϴ� ��Ҹ� ã�� �� ���� ���
                   �浹�ϴ� ��ü�� ã�ų� ���� �������� AABB �Ǵ� Raycasting����

   - ��� Ž��(Pathfinding - A �˰���)
    ~ NPC�� ��ֹ��� ���� ���� ã�� AI �ý��ۿ��� ���
    ~ std::priority_queue �� Ȱ���Ͽ� ������ ��� Ž�� ����

   - ���� ����(std::accumulate, std::inner_product)
    ~ ���� ���, ��� �м� � ���
    ~ ��� ����� ���� ���ϰų�, ���� ���� ����� �� ����

�ݺ���

   - ���� �ݺ���(std::forward_iterator)
    ~ ���������� �����͸� Ž���� �� ��� (std::list, std::forward_list � Ȱ��)
*/

