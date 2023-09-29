from pagerank import *

# transition_model test: OK

# corpus = {"1.html": {"2.html", "3.html"}, "2.html": {"3.html"}, "3.html": {"2.html"}}
# page = "1.html"
# damping_factor = 0.85
# result = transition_model(corpus, page, damping_factor)
# print(result)

# sample_pagerank seems OK, more accurate with more samples:

# corpus = {"1.html": {"2.html", "3.html"}, "2.html": {"3.html"}, "3.html": {"2.html"}}
# damping_factor = 0.85
# n = 10000000
# pagerank_estimate = sample_pagerank(corpus, damping_factor, n)
# print(pagerank_estimate)

# iterate_pagerank seems OK:

corpus = {"1.html": {"2.html", "3.html"}, "2.html": {"3.html"}, "3.html": {"2.html"}}
damping_factor = 0.85
pagerank = iterate_pagerank(corpus, damping_factor)
print(pagerank)