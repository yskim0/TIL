**MAC OS에서 SQL Developer 안열리는 문제**
- `sqldeveloper.sh` 파일에 JDK 위치를 나타내는 `$TMP_FILE`이 잘못된 경로를 가리키고 있었음.

**ORA-00604 Error**
- Add this rows into ..\sqldeveloper\ide\bin\ide.conf file
```
AddVMOption -Duser.language=en
AddVMOption -Duser.region=us
```
- 출처 : https://stackoverflow.com/questions/26470776/cant-connect-to-oracle-database-with-sql-developer-ora00604-error-occurred-at
