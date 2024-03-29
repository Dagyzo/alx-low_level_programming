#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
* hash_table_set - adds an element to the hash table
* @ht: the hash table to add or update the key/value to
* @key: the key (cannot be an empty string)
* @value: the value associated with the key (can be an empty string)
* Return: 1 if it succeeded, 0 otherwise
* In case of collision, add the new node at the beginning of the list
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	if (key == NULL || strlen(key) == 0)
	return (0);  /* key cannot be empty */

	/* Compute the hash code using the hash function */
	unsigned int hash = hash_function(key) % ht->size;

	/* Create a new node with the key and value */
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)

	{
	return (0);  /* failed to allocate memory for new node */
	}
	new_node->key = strdup(key);  /* duplicate the key string */
	new_node->value = strdup(value);  /* duplicate the value string */

	/* Handle collisions by adding the new node at the beginning of the list */
	if (ht->array[hash] != NULL)
	{
	new_node->next = ht->array[hash];
	}
	else
	{
	new_node->next = NULL;
	}
	ht->array[hash] = new_node;

	return (1);  /* success */
}
