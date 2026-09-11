#include <stdint.h>
#include <stdio.h>
#include "./tree-sitter/lib/include/tree_sitter/api.h"
#include <string.h>

const TSLanguage *tree_sitter_c (void);


int main () {
    // source code to parse 
    char * c_string= 
        "#include <stdio.h>\n"
        "  int main () {\n"
        "    printf (\"hello world\");\n"
        "return 0;\n"
        "}\n";


    TSParser *parser=ts_parser_new ();
    // then we set the parse langauges for c language 
    ts_parser_set_language (parser,tree_sitter_c());
    TSTree *tree=ts_parser_parse_string(parser,NULL, c_string, strlen (c_string));


    // get the node 
    TSNode root_node=ts_tree_root_node (tree);

    // then let print the values of tree part 
    for (int i=0; i<ts_node_child_count (root_node);i++) {

        TSNode child=ts_node_child (root_node,i);
        uint32_t count=ts_node_child_count(child);


        printf ("\n the child is :%d\n %s\n",i,ts_node_type(child));



        if (i==1) {

            
            TSNode child1=ts_node_child (root_node,1);
            uint32_t count=ts_node_child_count (child1);

            
        TSNode body=ts_node_child_by_field_name(child,"body",strlen("body"));
        printf ("\n the body type is :%s",ts_node_type (body));




         for (int j=0; j<count;j++) {

            TSNode child_function=ts_node_child (child1,j);
            uint32_t count=ts_node_child_count (child_function);
            printf ("\nthe child is %d,\n child_name : %s\n",j,ts_node_type (child_function));




            }

        }

    }
              

     }





   


