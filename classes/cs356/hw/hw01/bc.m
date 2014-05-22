%% Rules for performing backward chaining
%% k = knowledge base
%% g = goal rule
%% w = working memory
%% wk = working knowledge
%% r = rule
%% w = weight
%% b = belief measure
%% d = disbelief measure

%% Inference engine for backward-chaining
function bc_inf_eng(g, k, w)
% call kb_search on g
kb_search(g)

%% Need a sub-function to search the knowledge base
function kb_search(r, k)
