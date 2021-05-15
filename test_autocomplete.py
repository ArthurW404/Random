"""
Source:
https://importsem.com/query-google-suggestions-api-with-python/

Note:
Not sure how legal this is
"""

import requests
import json
from fake_useragent import UserAgent

keyword = input("Enter word:")

def get_suggestions(query):
    keyword = query
    keyword.replace(" ", "+")

    url = "http://suggestqueries.google.com/complete/search?output=firefox&q=" + keyword

    ua = UserAgent()
    headers = {}
    headers = {"user-agent": ua.chrome}
    response = requests.get(url, headers=headers, verify=False)

    suggestions = json.loads(response.text)
    print(suggestions)
    return suggestions[1]

suggestions = get_suggestions(keyword)
for word in suggestions:
    print(word)