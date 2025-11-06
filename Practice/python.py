import requests

# Replace these with your actual values
token = "65e0ab0fb05d75c4bb85c677075e3776a14adefb"
organization = "pranav0786"
project_key = "Pranav0786_ARomaMenu"

url = "https://sonarcloud.io/api/issues/search"
params = {
    "organization": organization,
    "projectKeys": project_key,         # e.g., BUG, VULNERABILITY, CODE_SMELL
    "p": 1,                      # Page number
    "ps": 50                     # Page size
}

response = requests.get(url, params=params, auth=(token, ""))
if response.status_code == 200:
    data = response.json()
    for issue in data.get("issues", []):
        print(f"{issue['severity']} — {issue['component']} — {issue['message']}")
else:
    print("Error:", response.status_code, response.text)

