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

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

struct Monster {
    int x = 20;  // ���� �ʱ� X ��ǥ
    int y = 10;  // ���� �ʱ� Y ��ǥ
    int health = 50;
    std::string image = "(''  )"; // ���� �̹���
};

class Game {
public:
    int characterX = 0; // ĳ���ʹ� X=0�� ����
    int characterY = 10; // ĳ���ʹ� Y=10�� ����
    std::string characterImage = "(  '')"; // ĳ���� �̹���
    std::vector<Monster> monsters; // ���� ����Ʈ

    void spawnMonster() {
        monsters.push_back({}); // ���ʹ� �׻� X=20���� ����
    }

    void update() {
        // ���� �̵� (��������)
        for (auto& monster : monsters) {
            monster.x--;
        }

        // ȭ�� ������ ���� ���� ����
        monsters.erase(std::remove_if(monsters.begin(), monsters.end(),
            [](const Monster& m) { return m.x < -1; }), monsters.end());

        // ĳ���� �տ� ���Ͱ� ������ ���� ����
        for (auto& monster : monsters) {
            if (monster.x == characterX) {
                battle(monster);
            }
        }
    }

    void battle(Monster& monster) {
        std::cout << "���� ����! ���� ü��: " << monster.health << "\n";
        monster.health -= 20; // ĳ���� ����
        if (monster.health <= 0) {
            std::cout << "���� óġ!\n";
            monster.x = -1; // ���� `remove_if`���� ���ŵ�
        }
    }

    void render() {
        std::cout << "\n���� ȭ��:\n";
        for (int i = 0; i < 21; i++) { // 21ĭ ȭ�� ǥ�� (X=0~20)
            bool isMonster = false;
            for (const auto& monster : monsters) {
                if (monster.x == i) {
                    std::cout << monster.image << " "; // ���� �̹��� ���
                    isMonster = true;
                    break;
                }
            }
            if (i == characterX) std::cout << characterImage << " "; // ĳ���� �̹��� ���
            else if (!isMonster) std::cout << "- ";
        }
        std::cout << "\n";
    }

    void run() {
        int step = 0;
        while (step++ < 30) {
            system("cls");
            // ������ �ݺ� ����
            if (step % 5 == 0) spawnMonster(); // ���� �ֱ�� ���� ����
            update();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // ������
        }
    }
};

int main() {
    Game game;
    game.run();
}