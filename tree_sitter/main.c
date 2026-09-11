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


    printf ("\n we started to type this codes here \n");

    TSParser *parser=ts_parser_new ();
    // then we set the parse langauges for c language 
    ts_parser_set_language (parser,tree_sitter_c());
    TSTree *tree=ts_parser_parse_string(parser,NULL, c_string, strlen (c_string));
       // get the node 
    TSNode root_node=ts_tree_root_node (tree);


    uint32_t error_offset;
    TSQueryError error_type;
        const char *query_string =
             "(identifier) @identifier "
             "(string_literal) @string";
          
    // and then we start the query
    TSQuery* query= ts_query_new (

            tree_sitter_c(),
            query_string,
            strlen(query_string),
            &error_offset,
            &error_type


            );
    TSQueryCursor *cursor=ts_query_cursor_new ();
    ts_query_cursor_exec (
            cursor,query,
            root_node
            );
    TSQueryMatch match;

while (ts_query_cursor_next_match(cursor, &match)) {

     printf("\nMATCH\n");
    printf("pattern index: %u\n", match.pattern_index);
    printf("capture count: %u\n", match.capture_count);
    for (uint32_t i = 0; i < match.capture_count; i++) {

        TSQueryCapture capture = match.captures[i];

        printf(
            "\nFOUND: %s\n",
            ts_node_type(capture.node)
        );

        printf(
            "start byte: %u\n",
            ts_node_start_byte(capture.node)
        );

        printf(
            "end byte: %u\n",
            ts_node_end_byte(capture.node)
        );
    }
}





 
    // then let print the values of tree part 
    for (int i=0; i<ts_node_child_count (root_node);i++) {

        TSNode child=ts_node_child (root_node,i);
        uint32_t count=ts_node_child_count(child);


        printf ("\n the child is :%d\n %s\n",i,ts_node_type(child));
        printf ("\n the child node start :%d and at :%d\n",ts_node_start_byte(child),ts_node_end_byte(child));
        printf ("\n start row :%d and start column  :%d  position \n",ts_node_start_point(child).row,ts_node_start_point(child).column);
        printf ("\n end row :%d and end column  :%d  position \n",ts_node_end_point(child).row,ts_node_end_point(child).column);
        printf ("\n the descendent of byte range or the caverage part is :%s\n",ts_node_type(ts_node_descendant_for_byte_range(child,21,24)));

        TSNode found=ts_node_descendant_for_byte_range (child,ts_node_start_byte(child),ts_node_end_byte (child));
        TSNode parent=ts_node_parent (found);
        printf ("\n the parent of this node is :%s\n",ts_node_type (parent));

        // next siblings 
        TSNode sib=ts_node_next_sibling(found);
        if (ts_node_is_null(sib)) {
        printf ("\n there is no next sibling");
        } 
        else {

            printf ("\n the sibling has been found :%s\n",ts_node_type(child));


        }
        TSNode pre=ts_node_prev_sibling (found);

        if (ts_node_is_null (pre)) {
    
        printf ("\n this node has no previous  sibling ");
        }
        else {
            printf ("\n the pre syblins is %s",ts_node_type (pre));


        }



        if (i==1) {

            
            TSNode child1=ts_node_child (root_node,1);
            uint32_t count=ts_node_child_count (child1);
            // where child one start and where he ends 
            

            
        TSNode body=ts_node_child_by_field_name(child,"body",strlen("body"));
        printf ("\n the body type is :%s",ts_node_type (body));





         for (int j=0; j<count;j++) {

            TSNode child_function=ts_node_child (child1,j);
            uint32_t count=ts_node_child_count (child_function);
            printf ("\nthe child is %d,\n child_name : %s\n",j,ts_node_type (child_function));
             printf ("\n the child node start :%d and at :%d\n",ts_node_start_byte(child_function),ts_node_end_byte(child_function));
             printf ("\n start row :%d and start column:%d  position \n",ts_node_start_point(child_function).row,ts_node_start_point(child_function).column);
             printf ("\n end row :%d and end column:%d  position \n",ts_node_end_point(child_function).row,ts_node_end_point(child_function).column);
             printf ("\n the descendent of byte range or the caverage part is :%s\n",ts_node_type(ts_node_descendant_for_byte_range(child_function,ts_node_start_byte(child_function),ts_node_end_byte(child_function))));







            }

        }

    }
              

     }





   


