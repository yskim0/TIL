# Ajax

## 수업의 목적

페이지 전체를 리로드(reload) 하지 않고 통신. (**비동기 통신)**

- MS
- 5년이 지나 구글이 가치를 알아봐 줌.
- **부분적으로 웹 페이지 갱신**
- 페이지를 전환할 때 마다 모든 내용을 변경하는 것 <<<<
필요한 내용만 부분적으로 load

---

- index.html 재사용하고
바뀔 수 있는 목록들(본문, 글제목, 타이틀)만 ajax로 동적으로 변경시켜주면 생산성 향상.
- 각각의 페이지마다 모두가 html 코드를 가질 필요가 없게 됨.
컨텐츠만을 컴팩트하게 가질 수 있음

`싱클 페이지 어플리케이션` 이라고 함.

---

## fetch API

    <!DOCTYPE html>
    <html>
        <body>
            <input type = "button" value="fetch" onclick="
            fetch('css').then(function(response){
                response.text().then(function(text){
                    alert(text);
                })
            })
            ">
        </body>
    </html>

- `css` 파일을 요청하고, 응답이 끝나면 `alert(text)` 가 실행하면서 서버가 응답한 데이터가 `text` 변수에 담겨 있다

    <!DOCTYPE html>
    <html>
        <body>
          <article>
    
          </article>
            <input type = "button" value="fetch" onclick="
            fetch('html').then(function(response){
                response.text().then(function(text){
                    document.querySelector('article').innerHTML = text;
                })
            })
            ">
        </body>
    </html>

---

    function callbackme(){
              console.log('response end');
            }
            fetch('html').then(callbackme);
            console.log(1);
            console.log(2);

- 웹 브라우저가 응답하는게 끝나면 그 때 `callbackme` 호출
    - 비동기적 실행

---

- 익명 함수

    <!DOCTYPE html>
    <html>
        <body>
          <article>
    
          </article>
            <input type = "button" value="fetch" onclick="
    
            /*
            fetch('html').then(function(response){
                response.text().then(function(text){
                    document.querySelector('article').innerHTML = text;
                })
            })
            */
            //Asynchronous
            fetch('html').then(function(response){
              if(response.status == '404'){
                alert('Not found')
              }
            });
            console.log(1);
            console.log(2);
            ">
        </body>
    </html>

---

## Ajax의 적용

    <!doctype html>
    <html>
    <head>
      <title>WEB1 - Welcome</title>
      <meta charset="utf-8">
      <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
      <script src="colors.js"></script>
    </head>
    <body>
      <h1><a href="index.html">WEB</a></h1>
      <input id="night_day" type="button" value="night" onclick="
        nightDayHandler(this);
      ">
      <ol>
        <li><a onclick="
          fetch('html').then(function(response){
            response.text().then(function(text){
              document.querySelector('article').innerHTML = text;
            })
          });
        ">HTML</a></li>
        <li><a onclick="
          fetch('css').then(function(response){
            response.text().then(function(text){
              document.querySelector('article').innerHTML = text;
            })
          });
          ">CSS</a></li>
        <li><a onclick="
          fetch('javascript').then(function(response){
            response.text().then(function(text){
              document.querySelector('article').innerHTML = text;
            })
          });">JavaScript</a></li>
      </ol>
       <article>
    
       </article>
      </p>
    </body>
    </html>

---

- 리팩토링 - 함수화
```
    <!doctype html>
    <html>
    <head>
      <title>WEB1 - Welcome</title>
      <meta charset="utf-8">
      <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
      <script src="colors.js"></script>
    </head>
    <body>
      <h1><a href="index.html">WEB</a></h1>
      <input id="night_day" type="button" value="night" onclick="
        nightDayHandler(this);
      ">
      <ol>
        <li><a onclick="fetchPage('html')">HTML</a></li>
        <li><a onclick="fetchPage('css')">CSS</a></li>
        <li><a onclick="fetchPage('javascript')">JavaScript</a></li>
      </ol>
       <article>
    
       </article>
       <script>
       function fetchPage(name){
         fetch(name).then(function(response){
           response.text().then(function(text){
             document.querySelector('article').innerHTML = text;
           })
         });
       }
       </script>
    
    </body>
    </html>
```
---

## fragment identifier - hash

- id를 통해 페이지 안에서 id에 대응하는 fragment로 올 수 있음.

    <script>
          if(location.hash) {
            console.log(location.hash.substr(1));
          } else {
          // Fragment doesn't exist
          }
        </script>

- pjax

---

## 글 목록 ajax로 구현하기

    <ol id ="nav">
    
      </ol>
       <article>
    
       </article>
       <script>
       function fetchPage(name){
         fetch(name).then(function(response){
           response.text().then(function(text){
             document.querySelector('article').innerHTML = text;
           })
         });
       }
       if(location.hash){
         fetchPage(location.hash.substr(2));
       } else{
         fetchPage('welcome');
       }
       fetch('list').then(function(response){
         response.text().then(function(text){
           document.querySelector('#nav').innerHTML = text;
         })
       });
       </script>

- `list`
```
    <li><a href= "#!html" onclick="fetchPage('html')">HTML</a></li>
    <li><a href= "#!css" onclick="fetchPage('css')">CSS</a></li>
    <li><a href= "#!javascript" onclick="fetchPage('javascript')">JavaScript</a></li>
    <li><a href= "#!ajax" onclick="fetchPage('ajax')">ajax</a></li>
```
- 이제 `index.html` 을 수정하지 않고 list 파일을 수정하여 바꿀 수 있음.

---

`list` 를 깔끔하게 쓰기 위해 `index.html`을 이렇게 바꾸면 편해짐.

    fetch('list').then(function(response){
         response.text().then(function(text){
           console.log(text);
           var items = text.split(',')
           var i = 0;
           var tags = '';
           while(i<items.length){
             var item = items[i];
             item = item.trim();
             console.log(item);
             //<li><a href= "#!html" onclick="fetchPage('html')">HTML</a></li>
             var tag = '<li><a href="#!'+item+'" onclick="fetchPage(\''+item+'\')">'+item+'</a></li>';
             console.log(tag);
             tags = tags + tag;
             i = i+1;
           }
           document.querySelector('#nav').innerHTML = tags;
         })
       });

`list`

    html,css,javascript,ajax

ajax말고도 다른 것들 추가하면 바로 바뀌는 것을 볼 수 있음.

---

## fetch API polyfill

[https://github.com/github/fetch](https://github.com/github/fetch)

    <script src="fetch/fetch.js"></script>