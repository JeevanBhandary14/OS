#include<stdio.h>
#include<stdbool.h>

int main() {
    int frames, pages, pageFaults = 0, pageHits = 0, i, j, k, l, minIndex = 0, min;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    
    int frame[frames], pageQueue[pages], counter[frames];
    bool isPageInFrame = false;

    printf("Enter the reference string: ");
    for(i = 0; i < pages; i++)
        scanf("%d", &pageQueue[i]);
    
    // Initializing frames and counter
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        counter[i] = 0;
    }

    // LRU page replacement algorithm
    for(i = 0; i < pages; i++) {
        isPageInFrame = false;
        
        // Check if the page is already in the frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == pageQueue[i]) {
                isPageInFrame = true;
                pageHits++;
                counter[j] = i + 1;
                break;
            }
        }

        // If the page is not in the frame, replace the least recently used page with the new page
        if(!isPageInFrame) {
            min = counter[0];
            minIndex = 0;
            for(k = 1; k < frames; k++) {
                if(counter[k] < min) {
                    min = counter[k];
                    minIndex = k;
                }
            }
            frame[minIndex] = pageQueue[i];
            counter[minIndex] = i + 1;
            pageFaults++;
        }

        // Display current frame contents
        printf("Frame: ");
        for(l = 0; l < frames; l++)
            printf("%d ", frame[l]);
        printf("\n");
    }
    
    // Calculate page fault ratio and page hit ratio
    float pageFaultRatio = (float)pageFaults / pages;
    float pageHitRatio = (float)pageHits / pages;

    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Page Fault Ratio: %.2f\n", pageFaultRatio);
    printf("Page Hit Ratio: %.2f\n", pageHitRatio);

    return 0;
}
