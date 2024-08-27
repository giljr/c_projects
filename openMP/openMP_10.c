#include <stdio.h>
#include <omp.h>

#define TOTAL_SEATS 1000 // Total number of seats available
#define THREADS 8        // Number of threads to simulate multiple users

// Simulate a complex function to calculate booking or cancellation
int book_ticket(int current_seat_count)
{
    // Simulate some computation
    return current_seat_count - 1;
}

int cancel_ticket(int current_seat_count)
{
    // Simulate some computation
    return current_seat_count + 1;
}

int main()
{
    int available_seats = TOTAL_SEATS; // Shared resource

// Start parallel region
#pragma omp parallel num_threads(THREADS)
    {
        int id = omp_get_thread_num(); // Get thread ID

        // Simulate booking or cancellation by each thread
        for (int i = 0; i < 100; ++i)
        { // Each thread makes 100 attempts
            if (id % 2 == 0)
            { // Even ID threads try to book tickets
#pragma omp critical
                {
                    if (available_seats > 0)
                    { // Check to avoid overbooking
                        available_seats = book_ticket(available_seats);
                        printf("Thread %d booked a ticket. Seats left: %d\n", id, available_seats);
                    }
                    else
                    {
                        printf("Thread %d tried to book a ticket, but none were available.\n", id);
                    }
                }
            }
            else
            { // Odd ID threads cancel tickets
#pragma omp critical
                {
                    if (available_seats < TOTAL_SEATS)
                    { // Check to avoid exceeding total seats
                        available_seats = cancel_ticket(available_seats);
                        printf("Thread %d canceled a ticket. Seats left: %d\n", id, available_seats);
                    }
                    else
                    {
                        printf("Thread %d tried to cancel a ticket, but none were booked.\n", id);
                    }
                }
            }
        }
    }

    // Final output after all threads have completed
    printf("Final number of available seats: %d\n", available_seats);

    return 0;
}
