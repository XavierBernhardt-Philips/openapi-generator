set executable=.\modules\openapi-generator-cli\target\openapi-generator-cli.jar

If Not Exist %executable% (
  mvn clean package
)

REM set JAVA_OPTS=%JAVA_OPTS% -Xmx1024M -DloggerPath=conf/log4j.properties
set ags=generate  --artifact-id "kotlin-ktor-petstore-client" -i modules\openapi-generator\src\test\resources\2_0\petstore.yaml -g kotlin-ktor-client -o samples\client\petstore\kotlin-ktor-client

java %JAVA_OPTS% -jar %executable% %ags%
