#include <stdio.h>
#include <limits.h>
#define MAX_CITIES 10

int n;  // Number of cities
int dist[MAX_CITIES][MAX_CITIES];  // Distance matrix
int best_cost = INT_MAX;
int best_path[MAX_CITIES];
int cur_path[MAX_CITIES];
int used[MAX_CITIES];

void dfs(int cur_pos, int count, int cost_so_far) {
    if (count == n) {
        cost_so_far += dist[cur_pos][0];  // Return to the starting city
        if (cost_so_far < best_cost) {
            best_cost = cost_so_far;
            for (int i = 0; i < n; i++) {
                best_path[i] = cur_path[i];
            }
        }
        return;
    }

    for (int city = 0; city < n; city++) {
        if (!used[city]) {
            used[city] = 1;
            cur_path[count] = city;
            dfs(city, count + 1, cost_so_far + dist[cur_pos][city]);
            used[city] = 0;
        }
    }
}

int main() {
    int source;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Distance from city %d to city %d: ", i + 1, j + 1);
            scanf("%d", &dist[i][j]);
        }
    }

    printf("Enter the starting city (1 to %d): ", n);
    scanf("%d", &source);
    source--;  // Adjust for 0-based indexing

    for (int i = 0; i < n; i++) used[i] = 0;
    best_cost = INT_MAX;

    used[source] = 1;
    cur_path[0] = source;
    dfs(source, 1, 0);

    printf("\nOptimal tour cost = %d\n", best_cost);
    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", best_path[i] + 1);
    }
    printf("%d\n", source + 1);  // Returning to the starting city

    return 0;
}
