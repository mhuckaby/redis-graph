#ifndef __OP_PRODUCE_RESULTS_H
#define __OP_PRODUCE_RESULTS_H

#include "op.h"
#include "../../parser/ast.h"
#include "../../redismodule.h"
#include "../../graph/query_graph.h"
#include "../../resultset/resultset.h"

/* ProduceResults
 * generates result set */

typedef struct {
    OpBase op;
    int refreshAfterPass;
    AST_Query *ast;
    Vector *return_elements; /* Vector of arithmetic expressions. */
    ResultSet *result_set;
    int init;
} ProduceResults;


/* Creates a new NodeByLabelScan operation */
OpBase* NewProduceResultsOp(AST_Query *ast, ResultSet *result_set);
ProduceResults* NewProduceResults(AST_Query *ast, ResultSet *resultset);

/* ProduceResults next operation
 * called each time a new result record is required */
OpResult ProduceResultsConsume(OpBase *op, QueryGraph* graph);

/* Restart iterator */
OpResult ProduceResultsReset(OpBase *ctx);

/* Frees ProduceResults */
void ProduceResultsFree(OpBase *ctx);

#endif
