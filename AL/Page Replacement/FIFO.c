#include<stdio.h>
#include<stdbool.h>

int main() {
    int frames, pages, pageFaults = 0, pageHits = 0, i, j, k, pointer = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    
    int frame[frames], pageQueue[pages];
    bool isPageInFrame = false;

    printf("Enter the reference string: ");
    for(i = 0; i < pages; i++)
        scanf("%d", &pageQueue[i]);
    
    // Initializing frames as -1 indicating empty frames
    for(i = 0; i < frames; i++)
        frame[i] = -1;

    // FIFO page replacement algorithm
    for(i = 0; i < pages; i++) {
        isPageInFrame = false;
        
        // Check if the page is already in the frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == pageQueue[i]) {
                isPageInFrame = true;
                pageHits++;
                break;
            }
        }

        // If the page is not in the frame, replace the oldest page with the new page
        if(!isPageInFrame) {
            frame[pointer] = pageQueue[i];
            pointer = (pointer + 1) % frames;
            pageFaults++;
        }

        // Display current frame contents
        printf("Frame: ");
        for(k = 0; k < frames; k++)
            printf("%d ", frame[k]);
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
