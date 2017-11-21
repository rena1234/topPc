#include <stdio.h>
#include <glib.h>

int main(){
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(hash, "Texas", "Austin");
    printf("The capital of Texas is %s\n", g_hash_table_lookup(hash, "Texas"));
    gboolean found = g_hash_table_remove(hash, "Texas");
}

