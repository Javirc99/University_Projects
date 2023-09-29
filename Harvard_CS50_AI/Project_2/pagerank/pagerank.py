import os
import random
import re
import sys

DAMPING = 0.85
SAMPLES = 10000


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python pagerank.py corpus")
    corpus = crawl(sys.argv[1])
    ranks = sample_pagerank(corpus, DAMPING, SAMPLES)
    print(f"PageRank Results from Sampling (n = {SAMPLES})")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")
    ranks = iterate_pagerank(corpus, DAMPING)
    print(f"PageRank Results from Iteration")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")


def crawl(directory):
    """
    Parse a directory of HTML pages and check for links to other pages.
    Return a dictionary where each key is a page, and values are
    a list of all other pages in the corpus that are linked to by the page.
    """
    pages = dict()

    # Extract all links from HTML files
    for filename in os.listdir(directory):
        if not filename.endswith(".html"):
            continue
        with open(os.path.join(directory, filename)) as f:
            contents = f.read()
            links = re.findall(r"<a\s+(?:[^>]*?)href=\"([^\"]*)\"", contents)
            pages[filename] = set(links) - {filename}

    # Only include links to other pages in the corpus
    for filename in pages:
        pages[filename] = set(
            link for link in pages[filename]
            if link in pages
        )

    return pages


def transition_model(corpus, page, damping_factor):
    """
    Return a probability distribution over which page to visit next,
    given a current page.

    With probability `damping_factor`, choose a link at random
    linked to by `page`. With probability `1 - damping_factor`, choose
    a link at random chosen from all pages in the corpus.
    """
    num_pages = len(corpus)
    probability_distribution = {}

    # Calculate the probability of choosing each link from the current page:
    if page in corpus and corpus[page]:
        for link in corpus[page]:
            probability_distribution[link] = damping_factor / len(corpus[page])

    # Calculate the probability of choosing a random page:
    random_probability = (1 - damping_factor) / num_pages

    # Distribute the random probability to all pages in the corpus:
    for p in corpus:
        probability_distribution.setdefault(p, 0)
        probability_distribution[p] += random_probability
    
    return probability_distribution
    


def sample_pagerank(corpus, damping_factor, n):
    """
    Return PageRank values for each page by sampling `n` pages
    according to transition model, starting with a page at random.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    # Initialize PageRank values for each page:
    pagerank = {page: 0 for page in corpus}

    # Start with a random page as the first sample:
    curr_page = random.choice(list(corpus.keys()))

    for _ in range(n):
        # Increment the PageRank for the current page
        pagerank[curr_page] += 1

        # Use the transition model to determine the next page:
        transition_probs = transition_model(corpus, curr_page, damping_factor)
        # Select the first (and only) item from the list of choices returned by random.choices, 
        # which represents the randomly selected next page.
        next_page = random.choices(list(transition_probs.keys()), weights= transition_probs.values())[0]

        # Update current page:
        curr_page = next_page

    # Normalize the PageRank values to sum to 1:
    total_samples = sum(pagerank.values())
    pagerank = {page: rank/total_samples for page, rank in pagerank.items()}

    return pagerank

def iterate_pagerank(corpus, damping_factor):
    """
    Return PageRank values for each page by iteratively updating
    PageRank values until convergence.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    # Initialize PageRank for each page as 1/N:
    num_pages = len(corpus)
    initial_rank = 1/num_pages
    pagerank = {page: initial_rank for page in corpus}

    # Define a function to calculate the new PageRank value for a page:
    def calculate_new_rank(page):
        new_rank = (1 - damping_factor) / num_pages
        for p, links in corpus.items():
            if page in links:
                new_rank += damping_factor * pagerank[p] / len(links)
        return new_rank
    
    # Iteratively calculate PageRank until we achieve convergence:
    while True:
        # Create a copy of the current PageRank values:
        new_pagerank = pagerank.copy()

        # Calculate the new PageRank values for all pages:
        for page in corpus:
            new_pagerank[page] = calculate_new_rank(page)

        # Check for convergence (if all of the difference between previous and new scores are smaller than 0.001)
        convergence = all(abs(new_pagerank[page] - pagerank[page]) < 0.001 for page in corpus)

        # Update the PageRank values
        pagerank = new_pagerank

        # If convergence achieved, exit the loop
        if convergence: 
            break

    return pagerank

if __name__ == "__main__":
    main()
