import requests
import base64
from io import BytesIO
from PIL import Image
import re
s=requests.Session()
def show_image():
    capt_url='https://cquv3.xuetangx.com/api/v1/code/captcha'
    capt=s.get(capt_url).json()
    img_str=capt['data']['img']
    captcha_key=capt['data']['captcha_key']
    img=base64.b64decode(img_str)
    with BytesIO() as f:
        f.write(img)
        im=Image.open(f)
        im.show()
    return input('input captcha'),captcha_key
def main():
    url='https://cquv3.xuetangx.com/#/home'
    headers={
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36'
    }
    s.get(url)
    s.headers=headers
    captcha,captcha_key=show_image()
    data={
        'login':'20184319',
        'password':'9704790k',
        'captcha':captcha,
        'captcha_key':captcha_key,
        'is_alliance':0
    }
    login_url='https://cquv3.xuetangx.com/api/v1/oauth/number/login'
    Res=s.post(login_url,data=data,allow_redirects=True)
    print(Res.content)
    s.get("/lms#/video/13751/34545/34beb5ad-888f-4fad-9e13-f3ddf1675760/107372/0"
main()