From almalinux:latest
RUN cd /home && mkdir hunter1 && touch t.txt && touch t2.txt && touch t3.txt
WORKDIR /home/hunter1
#RUN cd /home && mkdir hunter  
COPY programm1.sh /home/hunter1
#ENTRYPOINT ["home/hunter"]
#RUN cd /home/hunter1/programm1.sh 
RUN chmod +x programm1.sh
#CMD ["hunter12","/home/hunter1/programm1.sh"]

