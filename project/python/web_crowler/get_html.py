import requests
headers={
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
    AppleWebKit/537.36 (KHTML, like Gecko) \
    Chrome/79.0.3945.79 Safari/537.36'
}
url='https://cquv3.xuetangx.com/lms#/video/13751/34545/11d6e799-2f0c-4c1f-b90e-2f108ab1b2a4/109422/0/videoDiscussion'
res=requests.get(url,headers=headers)
print(res.text)