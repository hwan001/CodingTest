FROM python:3.10-slim

WORKDIR /app/python
# COPY python /app

# RUN pip install --no-cache-dir -r requirements.txt

VOLUME /app/python

# 지속적으로 변경되는 코드를 호스트에서 마운트할 것이므로 복사하지 않음
CMD ["tail", "-f", "/dev/null"]