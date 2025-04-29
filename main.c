#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // bool veri tipi için

#define MAX_USERS 100
#define MAX_FRIENDS 10
#define LINE_LENGTH 100

typedef struct {
    int user_id;
    int friends[MAX_FRIENDS];
    int friend_count;
} User;

User users[MAX_USERS];
int user_count = 0;

// Kullanıcı bul (ID ile)
User* find_user(int id) {
    int i;
    for (i = 0; i < user_count; i++) {
        if (users[i].user_id == id) {
            return &users[i];
        }
    }
    return NULL;
}

// Kullanıcı oluştur
void add_user(int id) {
    if (user_count < MAX_USERS) {
        users[user_count].user_id = id;
        users[user_count].friend_count = 0;
        user_count++;
    } else {
        printf("Maksimum kullanici sayisina ulasildi.\n");
    }
}

// Arkadaş ekle
void add_friend(int id1, int id2) {
    User* user1 = find_user(id1);
    User* user2 = find_user(id2);

    if (user1 && user2) {
        if (user1->friend_count < MAX_FRIENDS && user2->friend_count < MAX_FRIENDS) {
            bool friend1_exists = false;
            int i; // i burada fonksiyon dışında tanımlandı
            for (i = 0; i < user1->friend_count; i++) {
                if (user1->friends[i] == id2) {
                    friend1_exists = true;
                    break;
                }
            }
            if (!friend1_exists) {
                user1->friends[user1->friend_count++] = id2;
            }

            bool friend2_exists = false;
            for (i = 0; i < user2->friend_count; i++) {
                if (user2->friends[i] == id1) {
                    friend2_exists = true;
                    break;
                }
            }
            if (!friend2_exists) {
                user2->friends[user2->friend_count++] = id1;
            }
        } else {
            printf("Bir veya iki kullanicinin maksimum arkadas sayisina ulasildi.\n");
        }
    } else {
        printf("Kullanicilardan biri veya ikisi bulunamadi.\n");
    }
}

// DFS fonksiyonu
void dfs(int current_id, int target_depth, int current_depth, int visited[], int start_id) {
    visited[current_id] = 1;

    if (current_depth == target_depth) {
        if (current_id != start_id) { 
            printf("%d ", current_id);
        }
        return;
    }

    User* user = find_user(current_id);
    if (user == NULL) return;
    
    int i;
    for (i = 0; i < user->friend_count; i++) {
        int friend_id = user->friends[i];
        if (friend_id < MAX_USERS && !visited[friend_id]) { 
            dfs(friend_id, target_depth, current_depth + 1, visited, start_id);
        }
    }
}

// Belirli mesafedeki arkadaşları bulma
void find_friends_at_distance(int start_id, int distance) {
    if (start_id >= MAX_USERS) {
        printf("Gecersiz kullanici ID'si.\n");
        return;
    }
    int visited[MAX_USERS] = {0};
    printf("Kullanici %d icin %d adim uzakliktaki arkadaslar: ", start_id, distance);
    dfs(start_id, distance, 0, visited, start_id);
    printf("\n");
}

// Ortak arkadaşları bulma fonksiyonu
void find_common_friends(int id1, int id2) {
    User* user1 = find_user(id1);
    User* user2 = find_user(id2);

    if (user1 == NULL || user2 == NULL) {
        printf("Kullanicilardan biri bulunamadi.\n");
        return;
    }

    printf("Kullanici %d ve Kullanici %d icin ortak arkadaslar: ", id1, id2);

    int found = 0;
    int i, j; 
    for (i = 0; i < user1->friend_count; i++) {
        for (j = 0; j < user2->friend_count; j++) {
            if (user1->friends[i] == user2->friends[j]) {
                printf("%d ", user1->friends[i]);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("Yok.");
    }
    printf("\n");
}

// DFS topluluklar için
void dfs_community(int current_id, int visited[]) {
    visited[current_id] = 1;
    printf("%d ", current_id);

    User* user = find_user(current_id);
    if (user == NULL) return;

    int i;
    for (i = 0; i < user->friend_count; i++) {
        int friend_id = user->friends[i];
        if (friend_id < MAX_USERS && !visited[friend_id]) {
            dfs_community(friend_id, visited);
        }
    }
}

// Toplulukları bulma fonksiyonu
void find_communities() {
    int visited[MAX_USERS] = {0};
    int community_count = 0;

    printf("\nTopluluklar:\n");
    int i; 
    for (i = 0; i < user_count; i++) {
        int id = users[i].user_id;
        if (!visited[id]) {  
            printf("Topluluk %d: ", community_count + 1);
            dfs_community(id, visited);
            community_count++;  
            printf("\n");
        }
    }

    if (community_count == 0) {
        printf("Topluluk bulunamadi!\n");
    } else {
        printf("\nToplam %d topluluk bulundu.\n", community_count);
    }
}

// DFS ile erişilebilen kullanıcıları sayma
void dfs_influence(int current_id, int visited[], int* count) {
    visited[current_id] = 1;
    (*count)++;

    User* user = find_user(current_id);
    if (user == NULL) return;

    int i; 
    for (i = 0; i < user->friend_count; i++) {
        int friend_id = user->friends[i];
        if (friend_id < MAX_USERS && !visited[friend_id]) { 
            dfs_influence(friend_id, visited, count);
        }
    }
}

// Etkili kullanıcıyı bulma
void find_influential_user() {
    int max_reach = -1;
    int influential_user = -1;
    
    int i;
    for (i = 0; i < user_count; i++) {
        int id = users[i].user_id;
        if (id < MAX_USERS) {
            int visited[MAX_USERS] = {0};
            int count = 0;

            dfs_influence(id, visited, &count);
            count--;  

            if (count == 0) {
                count = 1;  // Kendisi etkili kullanıcı sayılır
            }

            printf("Kullanici %d -> %d kisiye erisebiliyor.\n", id, count);

            if (count > max_reach) {
                max_reach = count;
                influential_user = id;
            }
        }
    }

    if (influential_user == -1) {
        printf("En etkili kullanici: 0 (kendi kendine)\n");
    } else {
        printf("\nEn etkili kullanici: %d (%d kisiye erisebiliyor)\n", influential_user, max_reach);
    }
}

int main() {
    FILE *file = fopen("veriseti.txt", "r");
    if (file == NULL) {
        printf("veriseti.txt dosyası acilamadi!\n");
        return 1;
    }

    char line[LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n') continue;

        char command[10];
        int id1, id2;
        if (sscanf(line, "%s %d %d", command, &id1, &id2) >= 2) {
            if (strcmp(command, "USER") == 0) {
                add_user(id1);
            } else if (strcmp(command, "FRIEND") == 0) {
                add_friend(id1, id2);
            }
        } else if (sscanf(line, "%s %d", command, &id1) == 1) {
            if (strcmp(command, "USER") == 0) {
                add_user(id1);
            }
        }
    }
    fclose(file);

    // Kontrol: kullanıcıları ve arkadaşlarını yazdıralım
    printf("Kullanicilar ve Arkadaslari:\n");
    int i, j;
    for (i = 0; i < user_count; i++) {
        printf("Kullanici %d: ", users[i].user_id);
        for (j = 0; j < users[i].friend_count; j++) {
            printf("%d ", users[i].friends[j]);
        }
        printf("\n");
    }

    // DFS test: 101 kullanıcısından 2 adım uzaklıktaki arkadaşları bulalım
    printf("\n");
    find_friends_at_distance(101, 2);

    // Ortak arkadaş bulma örneği
    printf("\n");
    find_common_friends(101, 102);
    find_common_friends(101, 103);

    // Toplulukları tespit etme
    printf("\n");
    find_communities();

    printf("\n");
    find_influential_user();

    return 0;
}

