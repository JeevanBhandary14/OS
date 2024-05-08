#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FRAMES 100
#define MAX_PAGES 1000

int main() {
    int frames[MAX_FRAMES], pages[MAX_PAGES];
    int num_frames, num_pages;
    int page_hits = 0, page_faults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the page reference string: ");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize all frames to -1, indicating empty
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    // Optimal page replacement algorithm
    for (int i = 0; i < num_pages; i++) {
        bool page_found = false;

        // Check if page is already in frame
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == pages[i]) {
                page_hits++;
                page_found = true;
                break;
            }
        }

        // If page is not in frame, replace the page that will not be used for longest time
        if (!page_found) {
            int farthest_index = i + 1;
            int page_to_replace = -1;

            for (int j = 0; j < num_frames; j++) {
                int k;
                for (k = i + 1; k < num_pages; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest_index) {
                            farthest_index = k;
                            page_to_replace = j;
                        }
                        break;
                    }
                }
                // If a page will not be used anymore, replace it
                if (k == num_pages) {
                    page_to_replace = j;
                    break;
                }
            }

            frames[page_to_replace] = pages[i];
            page_faults++;
        }
    }

    printf("Total Page Hits: %d\n", page_hits);
    printf("Total Page Faults: %d\n", page_faults);
    printf("Hit Ratio: %.2f%%\n", (float) page_hits / num_pages * 100);
    printf("Fault Ratio: %.2f%%\n", (float) page_faults / num_pages * 100);

    return 0;
}
