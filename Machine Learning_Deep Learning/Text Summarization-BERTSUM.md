## Text Summarization using BERT
### 논문 : Fine-tune BERT for Extractive Summarization

- text summarization
  - **Extractive Summarization** — highlighter과 유사함. select segments of text 
  - **Abstractive Summarization** — paraphrasing과 유사함. 동일한 문장/단어가 아닐 수 있다.
  
- `ROUGE score`로 측정


- architecture

![arch](https://miro.medium.com/max/1230/1*Qe4jNewMZvnNQzchVIAesA.png)

- 궁금점
  - 여기서 ground truth data란 정확히 어떤 것인가
  
- BERTSUM repo. https://github.com/nlpyang/BertSum
