#include <stdio.h>

int main() {
    int n;
    printf("Enter number of logs: ");
    scanf("%d", &n);

    int id[n], time[n];

    for (int i = 0; i < n; i++) {
        int h, m;
        printf("Enter ID and time (HH MM): ");
        scanf("%d %d %d", &id[i], &h, &m);
        time[i] = h * 60 + m;   // convert to minutes
    }

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (time[i] > time[j]) {
                int tempTime = time[i];
                time[i] = time[j];
                time[j] = tempTime;

                int tempId = id[i];
                id[i] = id[j];
                id[j] = tempId;
            }
        }
    }

    printf("\nArranged Arrival Logs:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d  Time: %02d:%02d\n",
               id[i], time[i] / 60, time[i] % 60);
    }

    return 0;
}
