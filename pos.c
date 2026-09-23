// CEDIGO M-1L

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *getString(char *prompt);
int getInt(const char *prompt);
float getFloat(const char *prompt);

// Data struct for each product
typedef struct Product{
    char *name;
    float price;
    int quantity;

    struct Product *next;
} Product;


int main(void) {
    // Product list
    Product *products = NULL;

    // Repeatedly ask the information for each product until the user decides to stop
    while (1) {
        // Ask for user input Product name, price, and quantity
        char *name = getString("Enter name: ");
        while (name == NULL) {
            printf("Name cannot be empty. Please enter a valid name.\n");
            name = getString("Enter name: ");
        }
        float price = getFloat("Enter Price: ₱");
        int quantity = getInt("Enter Quantity: ");
        

        //sprintf("Product: %s, Price: %.2f, Quantity: %d\n", name, price, quantity);
        // Create new product node
        Product *n = malloc(sizeof(Product));
        if (n == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Store the information in the list
        n->name = strdup(name);
        n->price = price;
        n->quantity = quantity;
        n->next = products;
        products = n;

        // Ask the user if they want to add another product
        char *response = getString("Do you want to add another product? (y/n): ");
        if (response == NULL || (response[0] != 'y' && response[0] != 'Y')) {
            break;
        }
    }


}


char *getString(char *prompt)
{
    static char string[100];

    printf("%s", prompt);

    if (fgets(string, sizeof(string), stdin) == NULL)
    {
        return NULL;
    }

    string[strcspn(string, "\n")] = '\0';

    if (strlen(string) == 0)
    {
        return NULL;
    }

    return string;
}

int getInt(const char *prompt)
{
    char input[100];
    int number;
    char extra;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input ended.\n");
            return -1;
        }

        // Detect empty input (just Enter)
        if (input[0] == '\n')
        {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        // Check that the input is a valid integer
        if (sscanf(input, "%d %c", &number, &extra) == 1 && number > 0)
        {
            return number;
        }

        printf("Invalid input. Please enter a positive integer.\n");
    }
}

float getFloat(const char *prompt)
{
    char input[100];
    float number;
    char extra;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input ended.\n");
            return -1;
        }

        // Detect empty input (just Enter)
        if (input[0] == '\n')
        {
            printf("Invalid input. Please enter a non-negative number.\n");
            continue;
        }

        // Check that the input is a valid float
        if (sscanf(input, "%f %c", &number, &extra) == 1 && number >= 0)
        {
            return number;
        }

        printf("Invalid input. Please enter a non-negative number.\n");
    }
}