---
title: Cyberops
description: Cours de cyberops
---

L'IDS est une sonde d'intrusion. Port mirroring vers cette sonde qui analyse en différé.
L'IPS est une sonde de prévention d'intrusion. Le trafic passe directement par la sonde qui fonctionne en temps réel.

RTT: Round Time Trip
MSS: Maximum Size Segment (volume de data échangeable)
PAR: Positive Acknowledgement Retransmission

Déni de service TCP: on envoie plein de SYN sans répondre aux ACK.

Réseau botnet: réseau de postes zombies.

Attaque bail DHCP: Les clients renouvellent leur bail à 50% du temps restant. Si pas de réponse, il refait un renew a 75% du temps puis un nouveau Discovery a 87.5% du bail. On peut spoof le serveur DHCP si on lui prend toutes ses adresses (il arrête de répondre)

Outils: packet tracer packet bulker | scapy (forge de trammes) | softperfect network protocol analyzer packet sender | locky |

On peut utiliser le corps du PING pour transmettre des données

Un switch avec une table saturée passe en mode hub.

## CCNA 

<p><strong>1. Which two statements are characteristics of a virus? (Choose two.)</strong></p>
<ul>
<li><span ">A virus typically requires end-user activation.</span></b></li>
<li><span ">A virus can be dormant and then activate at a specific time or date.</span></b></li>
<p><strong>2. What is a characteristic of a Trojan horse as it relates to network security?</strong></p>
<li><span ">Malware is contained in a seemingly legitimate executable program.</span></b></li>
<p><strong>3. What technique is used in social engineering attacks?</strong></p>
<li><span ">phishing</span></b></li>
<p><strong>4. What is a purpose of implementing VLANs on a network?</strong></p>
<ul>
<li><span ">They can separate user traffic.</span></b></li>
<p><strong>5. Refer to the exhibit. A cybersecurity analyst is viewing packets forwarded by switch S2. What addresses will identify frames containing data sent from PCA to PCB?</strong></p>
<p><span ">Src IP: 192.168.1.212</span><br />
<p><strong>6. A cybersecurity analyst needs to collect alert data. What are three detection tools to perform this task in the Security Onion architecture? (Choose three.)</strong></p>
<ul>
<li><span ">CapME</span></b></li>
<li><span ">Wazuh</span></b></li>
<li><span ">Zeek</span></b></li>
<p><strong>7. Match the Security Onion tool with the description.</strong></p>
<p><img decoding="async" class="aligncenter size-full wp-image-58413" src="https://itexamanswers.net/wp-content/uploads/2020/09/7Q.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 3" width="625" height="523" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 3" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/7Q.jpg 625w, https://itexamanswers.net/wp-content/uploads/2020/09/7Q-300x251.jpg 300w" sizes="(max-width: 625px) 100vw, 625px" /></p>
<p><strong>8. In network security assessments, which type of test is used to evaluate the risk posed by vulnerabilities to a specific organization including assessment of the likelihood of attacks and the impact of successful exploits on the organization?</strong></p>
<li><span ">risk analysis</span></b></li>
<p><strong>9. Match the server profile element to the description. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58414" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q9CyberOps-Associate.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 4" width="490" height="524" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 4" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q9CyberOps-Associate.jpg 490w, https://itexamanswers.net/wp-content/uploads/2020/09/Q9CyberOps-Associate-281x300.jpg 281w" sizes="(max-width: 490px) 100vw, 490px" /></p>
<div class="message_box success"><p><strong>Explanation:</strong> The elements of a server profile include the following:Listening ports – the TCP and UDP daemons and ports that are allowed to be open on the server<br />
User accounts – the parameters defining user access and behavior<br />
Service accounts – the definitions of the type of service that an application is allowed to run on a given host<br />
Software environment – the tasks, processes, and applications that are permitted to run on the server</p></div>
<p><strong>10. In addressing an identified risk, which strategy aims to shift some of the risk to other parties?</strong></p>
<li><span ">risk sharing</span></b></li>
<p><strong>11. What is a network tap?</strong></p>
<p><strong>12. Match the monitoring tool to the definition.</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58415" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q12CyberOps-Associate.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 5" width="586" height="506" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 5" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q12CyberOps-Associate.jpg 586w, https://itexamanswers.net/wp-content/uploads/2020/09/Q12CyberOps-Associate-300x259.jpg 300w" sizes="(max-width: 586px) 100vw, 586px" /></p>
<p><strong>13. If a SOC has a goal of 99.999% uptime, how many minutes of downtime a year would be considered within its goal?</strong></p>
<ul>
<li><span ">Approximately 5 minutes per year.</span></b></li>
<p><strong>14. The HTTP server has responded to a client request with a 200 status code. What does this status code indicate?</strong></p>
<li><span ">The request was completed successfully.</span></b></li>
<p><strong>15. What is an advantage for small organizations of adopting IMAP instead of POP?</strong></p>
<li><span ">Messages are kept in the mail servers until they are manually deleted from the email client.</span></b></li>
<p><strong>16. What debugging security tool can be used by black hats to reverse engineer binary files when writing exploits?</strong></p>
<ul>
<li><span ">WinDbg</span></b></li>
<p><strong>18. What are two features of ARP? (Choose two.)</strong></p>
<li><span ">If a host is ready to send a packet to a local destination device and it has the IP address but not the MAC address of the destination, it generates an ARP broadcast.</span></b></li>
<li><span ">If a device receiving an ARP request has the destination IPv4 address, it responds with an ARP reply.</span></b></li>
<p><strong>19. What is a property of the ARP table on a device?</strong></p>
<ul>
<li><span ">Entries in an ARP table are time-stamped and are purged after the timeout expires.</span></b></li>
<li><span ">to allow users to browse the Internet anonymously</span></b></li>
<p><strong>21. Which two network protocols can be used by a threat actor to exfiltrate data in traffic that is disguised as normal network traffic? (Choose two.)</strong></p>
<li><span ">DNS</span></b></li>
<li><span ">HTTP</span></b></li>
<p><strong>22. What is a key difference between the data captured by NetFlow and data captured by Wireshark?</strong></p>
<li><span ">NetFlow collects metadata from a network flow whereas Wireshark captures full data packets.</span></b></li>
<p><strong>23. Which tool captures full data packets with a command-line interface only?</strong></p>
<li><span ">tcpdump</span></b></li>
<p><strong>24. Which method can be used to harden a device?</strong></p>
<li><span ">use SSH and disable the root account access over SSH</span></b></li>
</ul>
<div class="message_box success"><p><strong>Explanation:</strong> The basic best practices for device hardening are as follows:<br />
<p><strong>25. In a Linux operating system, which component interprets user commands and attempts to execute them?</strong></p>
<li><span ">shell</span></b></li>
<p><strong>26. A network administrator is configuring an AAA server to manage RADIUS authentication. Which two features are included in RADIUS authentication? (Choose two.)</strong></p>
<li><span ">single process for authentication and authorization</span></b></li>
<li><span ">hidden passwords during transmission</span></b></li>
<p><strong>27. What is privilege escalation?</strong></p>
<li><span ">Vulnerabilities in systems are exploited to grant higher levels of privilege than someone or some process should have.</span></b></li>
<p><strong>28. What two assurances does digital signing provide about code that is downloaded from the Internet? (Choose two.)</strong></p>
<li><span ">The code has not been modified since it left the software publisher.</span></b></li>
<li><span ">The code is authentic and is actually sourced by the publisher.</span></b></li>
<p><strong>29. An IT enterprise is recommending the use of PKI applications to securely exchange information between the employees. In which two cases might an organization use PKI applications to securely exchange information between users? (Choose two.)</strong></p>
<ul>
<li><span>HTTPS web service</span></strong></li>
<li><span>802.1x authentication</span></strong></li>
<p><strong>30. Which measure can a security analyst take to perform effective security monitoring against network traffic encrypted by SSL technology?</strong></p>
<li><span ">Deploy a Cisco SSL Appliance.</span></b></li>
<p><strong>31. An administrator is trying to develop a BYOD security policy for employees that are bringing a wide range of devices to connect to the company network. Which three objectives must the BYOD security policy address? (Choose three.)</strong></p>
<li><span ">Rights and activities permitted on the corporate network must be defined.</span></b></li>
<li><span ">Safeguards must be put in place for any personal device being compromised.</span></b></li>
<li><span ">The level of access of employees when connecting to the corporate network must be defined.</span></b></li>
<p><strong>32. Match the security policy with the description. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58455" src="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_200447.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 7" width="727" height="843" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 7" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_200447.jpg 727w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_200447-259x300.jpg 259w" sizes="(max-width: 727px) 100vw, 727px" /></p>
<table>
<tbody>
<tr>
<td>identifies network applications and uses that are acceptable to the organization</td>
<td>acceptable use policy (AUP)</td>
</tr>
<tr>
<td>identifies how remote users can access a network and what is accessible via remote connectivity</td>
<td>remote access policy</td>
</tr>
<tr>
<td>specifies authorized persons that can have access to network resources and identity verification procedures</td>
<td>identification and authentication policy</td>
</tr>
<tr>
<td>specifies network device operating systems and end user application update procedures</td>
<td>network maintenance policy</td>
</tr>
</tbody>
</table>
<p><strong>33. Match the attack to the definition. (Not all options are used.)</strong></p>
<li><span ">SQL injection</span></b></li>
<p><strong>35. What are two characteristics of Ethernet MAC addresses? (Choose two.)</strong></p>
<li><span ">They are expressed as 12 hexadecimal digits.</span></b></li>
<li><span ">They are globally unique.</span></b></li>
<p><strong>36. A user calls to report that a PC cannot access the internet. The network technician asks the user to issue the command <code>ping 127.0.0.1</code> in a command prompt window. The user reports that the result is four positive replies. What conclusion can be drawn based on this connectivity test?</strong></p>
<li><span ">The TCP/IP implementation is functional.</span></b></li>
<li><span ">They always try to cause some harm to an individual or organization.</span></b></li>
<li><span ">a type of ransomware</span></b></li>
<p><strong>39. Which ICMPv6 message type provides network addressing information to hosts that use SLAAC?</strong></p>
<li><span "><strong>router advertisement</strong></span></li>
<p><strong>40. Which tol included in the Security Onion is a series of software plugins that send different types of data to the Elasticsearch data stores?</strong></p>
<li><span "><strong>Beats</strong></span></li>
<p><strong>41. Which two types of unreadable network traffic could be eliminated from data collected by NSM? (Choose two.)</strong></p>
<li><span ">IPsec traffic</span></b></li>
<li><span ">SSL traffic</span></b></li>
<p><strong>42. Which core open source component of the Elastic-stack is responsible for accepting the data in its native format and making elements of the data consistent across all sources?</strong></p>
<ul>
<li><span ">Logstash</span></b></li>
<p><strong>43. Match the security incident stakeholder with the role.</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58419" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q43CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 9" width="551" height="504" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 9" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q43CyberOps-Associate.png 551w, https://itexamanswers.net/wp-content/uploads/2020/09/Q43CyberOps-Associate-300x274.png 300w" sizes="(max-width: 551px) 100vw, 551px" /></p>
<li><span ">attrition</span></b></li>
<p><strong>45. Match the security organization with its security functions. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58420" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q45CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 10" width="493" height="528" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 10" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q45CyberOps-Associate.png 493w, https://itexamanswers.net/wp-content/uploads/2020/09/Q45CyberOps-Associate-280x300.png 280w" sizes="(max-width: 493px) 100vw, 493px" /></p>
<p><strong>46. What is a characteristic of CybOX?</strong></p>
<li><span ">It is a set of standardized schemata for specifying, capturing, characterizing, and communicating events and properties of network operations.</span></b></li>
<p><strong>47. After host A receives a web page from server B, host A terminates the connection with server B. Match each step to its correct option in the normal termination process for a TCP connection. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58421" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q47CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 11" width="584" height="506" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 11" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q47CyberOps-Associate.png 584w, https://itexamanswers.net/wp-content/uploads/2020/09/Q47CyberOps-Associate-300x260.png 300w" sizes="(max-width: 584px) 100vw, 584px" /></p>
<p><strong>48. What are two ways that ICMP can be a security threat to a company? (Choose two.)</strong></p>
<li><span ">by collecting information about a network</span></b></li>
<li><span ">by providing a conduit for DoS attacks</span></b></li>
<p><strong>49. Which three IPv4 header fields have no equivalent in an IPv6 header? (Choose three.)</strong></p>
<li><span ">fragment offset</span></b></li>
<li><span ">flag</span></b></li>
<li><span ">identification</span></b></li>
<p><strong>50. Which two <code>net</code> commands are associated with network resource sharing? (Choose two.)</strong></p>
<li><span ">net share</span></b></li>
<li><span ">net use</span></b></li>
<p><strong>51. Match the Windows 10 Registry key with its description. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58422" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q51CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 12" width="552" height="534" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 12" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q51CyberOps-Associate.png 552w, https://itexamanswers.net/wp-content/uploads/2020/09/Q51CyberOps-Associate-300x290.png 300w" sizes="(max-width: 552px) 100vw, 552px" /></p>
<p><strong>52. Which PDU format is used when bits are received from the network medium by the NIC of a host?</strong></p>
<li><span ">frame</span></b></li>
<p><strong>53. A user is executing a tracert to a remote device. At what point would a router, which is in the path to the destination device, stop forwarding the packet?</strong></p>
<li><span ">when the value in the TTL field reaches zero</span></b></li>
<p><strong>54. Refer to the exhibit. What solution can provide a VPN between site A and site B to support encapsulation of any Layer 3 protocol between the internal networks at each site?</strong></p>
<li><span ">a GRE tunnel</span></b></li>
<p><strong>55. For what purpose would a network administrator use the Nmap tool?</strong></p>
<li><span ">detection and identification of open ports</span></b></li>
<p><strong>56. Match the network service with the description.</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58424" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q56CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 14" width="597" height="524" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 14" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q56CyberOps-Associate.png 597w, https://itexamanswers.net/wp-content/uploads/2020/09/Q56CyberOps-Associate-300x263.png 300w" sizes="(max-width: 597px) 100vw, 597px" /></p>
<p><strong>57. A client application needs to terminate a TCP communication session with a server. Place the termination process steps in the order that they will occur. (Nat all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter wp-image-58425" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q57CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 15" width="590" height="645" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 15" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q57CyberOps-Associate.png 492w, https://itexamanswers.net/wp-content/uploads/2020/09/Q57CyberOps-Associate-274x300.png 274w" sizes="(max-width: 590px) 100vw, 590px" /></p>
<p><strong>58. Match the attack surface with attack exploits.</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58426" src="https://itexamanswers.net/wp-content/uploads/2020/09/Q58CyberOps-Associate.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 16" width="588" height="515" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 16" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/Q58CyberOps-Associate.png 588w, https://itexamanswers.net/wp-content/uploads/2020/09/Q58CyberOps-Associate-300x263.png 300w" sizes="(max-width: 588px) 100vw, 588px" /></p>
<p><strong>59. Match the Linux host-based firewall application with its description.</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-79873" src="https://itexamanswers.net/wp-content/uploads/2020/09/59_2022-06-28_112112.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 17" width="903" height="717" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 17" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/59_2022-06-28_112112.jpg 903w, https://itexamanswers.net/wp-content/uploads/2020/09/59_2022-06-28_112112-300x238.jpg 300w, https://itexamanswers.net/wp-content/uploads/2020/09/59_2022-06-28_112112-768x610.jpg 768w" sizes="(max-width: 903px) 100vw, 903px" /></p>
<p><strong>60. What network attack seeks to create a DoS for clients by preventing them from being able to obtain a DHCP lease?</strong></p>
<ul>
<li><span "><strong>DHCP starvation</strong></span></li>
<p><strong>61. Refer to the exhibit. If Host1 were to transfer a file to the server, what layers of the TCP/IP model would be used?</strong><br />
<li><span "><strong>application, transport, Internet, and network access layers</strong></span></li>
<p><strong>62. A company has a file server that shares a folder named Public. The network security policy specifies that the Public folder is assigned Read-Only rights to anyone who can log into the server while the Edit rights are assigned only to the network admin group. Which component is addressed in the AAA network service framework?</strong></p>
<li><span "><strong>authorization</strong></span></li>
<p><strong>63. Match the destination network routing table entry type with a defintion.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58461" src="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_194941.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 19" width="653" height="481" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 19" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_194941.jpg 653w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_194941-300x221.jpg 300w" sizes="(max-width: 653px) 100vw, 653px" /></p>
<p><strong>64. A person coming to a cafe for the first time wants to gain wireless access to the Internet using a laptop. What is the first step the wireless client will do in order to communicate over the network using a wireless management frame?</strong></p>
<li><span "><strong>discover the AP</strong></span></li>
<p><strong>65. A device has been assigned the IPv6 address of 2001:0db8:cafe:4500:1000:00d8:0058:00ab/64. Which is the network identifier of the device?</strong></p>
<li><span "><strong>2001:0db8:cafe:4500</strong></span></li>
<p><strong>66. An administrator wants to create four subnetworks from the network address 192.168.1.0/24. What is the network address and subnet mask of the second useable subnet?</strong></p>
<p><span "><strong>subnetwork 192.168.1.64<br />
<p><strong>67. What term describes a set of software tools designed to increase the privileges of a user or to grant access to the user to portions of the operating system that should not normally be allowed?</strong></p>
<li><span "><strong>rootkit</strong></span></li>
<p><strong>68. The IT security personnel of an organization notice that the web server deployed in the DMZ is frequently targeted by threat actors. The decision is made to implement a patch management system to manage the server. Which risk management strategy method is being used to respond to the identified risk?</strong></p>
<li><span "><strong>risk reduction</strong></span></li>
<p><strong>69. What are three characteristics of an information security management system? (Choose three.)</strong></p>
<li><span "><strong>It is a systematic and multilayered approach to cybersecurity.</strong></span></li>
<li><span "><strong>It consists of a set of practices that are systematically applied to ensure continuous improvement in information security.</strong></span></li>
<li><span "><strong>It consists of a management framework through which an organization identifies, analyzes, and addresses information security risks.</strong></span></li>
<p><strong>70. Which three technologies should be included in a SOC security information and event management system? (Choose three.)</strong></p>
<li><span "><strong>event collection, correlation, and analysis</strong></span></li>
<li><span "><strong>security monitoring</strong></span></li>
<li><span "><strong>threat intelligence</strong></span></li>
<p><strong>71. What part of the URL, http://www.cisco.com/index.html, represents the top-level DNS domain?</strong></p>
<li><span "><strong>.com</strong></span></li>
<p><strong>72. What best describes the security threat of spoofing?</strong></p>
<li><span "><strong>making data appear to come from a source that is not the actual source</strong></span></li>
<p><strong>73. A newly created company has fifteen Windows 10 computers that need to be installed before the company can open for business. What is a best practice that the technician should implement when configuring the Windows Firewall?</strong></p>
<li><span "><strong>After implementing third party security software for the company, the technician should verify that the Windows Firewall is disabled.</strong></span></li>
<p><strong>74. Which statement defines the difference between session data and transaction data in logs?</strong></p>
<li><span "><strong>Session data records a conversation between hosts, whereas transaction data focuses on the result of network sessions.</strong></span></li>
<p><strong>75. Match the network monitoring data type with the description.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58462" src="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_201708.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 20" width="651" height="511" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 20" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_201708.jpg 651w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_201708-300x235.jpg 300w" sizes="(max-width: 651px) 100vw, 651px" /></p>
<p><strong>76. Which device supports the use of SPAN to enable monitoring of malicious activity?</strong></p>
<li><span "><strong>Cisco Catalyst switch</strong></span></li>
<p><strong>77. Which term is used for describing automated queries that are useful for adding efficiency to the cyberoperations workflow?</strong></p>
<li><span "><strong>playbook</strong></span></li>
<p><strong>78. When ACLs are configured to block IP address spoofing and DoS flood attacks, which ICMP message should be allowed both inbound and outbound?</strong></p>
<li><span "><strong>source quench</strong></span></li>
<p><strong>79. After a security monitoring tool identifies a malware attachment entering the network, what is the benefit of performing a retrospective analysis?</strong></p>
<li><span "><strong>A retrospective analysis can help in tracking the behavior of the malware from the identification point forward.</strong></span></li>
<p><strong>80. Which two data types would be classified as personally identifiable information (PII)? (Choose two.)</strong></p>
<li><span "><strong>vehicle identification number</strong></span></li>
<li><span "><strong>Facebook photographs</strong></span></li>
<p><strong>81. A help desk technician notices an increased number of calls relating to the performance of computers located at the manufacturing plant. The technician believes that botnets are causing the issue. What are two purposes of botnets? (Choose two.)</strong></p>
<li><span "><strong>to transmit viruses or spam to computers on the same network</strong></span></li>
<li><span "><strong>to attack other computers</strong></span></li>
<p><strong>82. Which two statements describe the use of asymmetric algorithms? (Choose two.)</strong></p>
<li><span "><strong>If a public key is used to encrypt the data, a private key must be used to decrypt the data.</strong></span></li>
<li><span "><strong>If a private key is used to encrypt the data, a public key must be used to decrypt the data.</strong></span></li>
<p><strong>83. Which three security services are provided by digital signatures? (Choose three.)</strong></p>
<li><span "><strong>guarantees data has not changed in transit</strong></span></li>
<li><span "><strong>provides data encryption</strong></span></li>
<li><span "><strong>authenticates the source</strong></span></li>
<p><strong>84. What are two methods to maintain certificate revocation status? (Choose two.)</strong></p>
<li><span "><strong>CRL</strong></span></li>
<li><span "><strong>OCSP</strong></span></li>
<p><strong>85. What are two uses of an access control list? (Choose two.)</strong></p>
<li><span "><strong>ACLs provide a basic level of security for network access.</strong></span></li>
<li><span "><strong>ACLs can control which areas a host can access on a network.</strong></span></li>
<p><strong>86. A client is using SLAAC to obtain an IPv6 address for the interface. After an address has been generated and applied to the interface, what must the client do before it can begin to use this IPv6 address?</strong></p>
<li><span "><strong>It must send an ICMPv6 Neighbor Solicitation message to ensure that the address is not already in use on the network.</strong></span></li>
<p><strong>87. A technician is troubleshooting a network connectivity problem. Pings to the local wireless router are successful but pings to a server on the Internet are unsuccessful. Which CLI command could assist the technician to find the location of the networking problem?</strong></p>
<li><span "><strong>tracert</strong></span></li>
<p><strong>88. What are two evasion techniques that are used by hackers? (Choose two.)</strong></p>
<li><span "><strong>pivot</strong></span></li>
<li><span "><strong>rootkit</strong></span></li>
<p><strong>89. When a security attack has occurred, which two approaches should security professionals take to mitigate a compromised system during the Actions on Objectives step as defined by the Cyber Kill Chain model? (Choose two.)</strong></p>
<li><span "><strong>Perform forensic analysis of endpoints for rapid triage.</strong></span></li>
<li><span "><strong>Detect data exfiltration, lateral movement, and unauthorized credential usage.</strong></span></li>
<p><strong>90. Place the seven steps defined in the Cyber Kill Chain in the correct order.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58463" src="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202341.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 21" width="651" height="719" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 21" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202341.jpg 651w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202341-272x300.jpg 272w" sizes="(max-width: 651px) 100vw, 651px" /></p>
<p><strong>91. Which field in the TCP header indicates the status of the three-way handshake process?</strong></p>
<li><span "><strong>control bits</strong></span></li>
<p><strong>92. A user opens three browsers on the same PC to access www.cisco.com to search for certification course information. The Cisco web server sends a datagram as a reply to the request from one of the web browsers. Which information is used by the TCP/IP protocol stack in the PC to identify which of the three web browsers should receive the reply?</strong></p>
<li><span "><strong>the destination port number</strong></span></li>
<p><strong>93. What are two scenarios where probabilistic security analysis is best suited? (Choose two.)</strong></p>
<li class="correct_answer">when random variables create difficulty in knowing with certainty the outcome of any given event</li>
<li class="correct_answer">when analyzing applications designed to circumvent firewalls</li>
<p><strong>94. Which tool is a web application that provides the cybersecurity analyst an easy-to-read means of viewing an entire Layer 4 session?</strong></p>
<li><span "><strong>CapME</strong></span></li>
<p><strong>95. Match the category of attacks with the description. (Not all options are used.)</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58464" src="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 22" width="725" height="727" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 22" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739.jpg 725w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739-300x300.jpg 300w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739-150x150.jpg 150w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739-200x200.jpg 200w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739-80x80.jpg 80w, https://itexamanswers.net/wp-content/uploads/2020/10/2020-10-19_202739-75x75.jpg 75w" sizes="(max-width: 725px) 100vw, 725px" /></p>
<p><strong>96. What are two characteristics of the SLAAC method for IPv6 address configuration? (Choose two.)</strong></p>
<li><span "><strong>The default gateway of an IPv6 client on a LAN will be the link-local address of the router interface attached to the LAN.</strong></span></li>
<li><span "><strong>IPv6 addressing is dynamically assigned to clients through the use of ICMPv6.</strong></span></li>
<p><strong>97. A technician notices that an application is not responding to commands and that the computer seems to respond slowly when applications are opened. What is the best administrative tool to force the release of system resources from the unresponsive application?</strong></p>
<li><span "><strong>Task Manager</strong></span></li>
<p><strong>98. How can statistical data be used to describe or predict network behavior?</strong></p>
<li><span "><strong>by comparing normal network behavior to current network behavior</strong></span></li>
<p><strong>99. Which metric in the CVSS Base Metric Group is used with an attack vector?</strong></p>
<li><span "><strong>the proximity of the threat actor to the vulnerability</strong></span></li>
<div class="message_box success"><p><strong>Explanation:</strong> This is a metric that reflects the proximity of the threat actor to the vulnerable component. The more remote the threat actor is to the component, the higher the severity. Threat actors close to your network or inside your network are easier to detect and mitigate.</p></div>
<p><strong>100. Which NIST Cybersecurity Framework core function is concerned with the development and implementation of safeguards that ensure the delivery of critical infrastructure services?</strong></p>
<li><span "><strong>protect</strong></span></li>
<li><span "><strong>amplification</strong></span></li>
<li><span "><strong>reflection</strong></span></li>
<p><strong>102. What is the primary objective of a threat intelligence platform (TIP)?</strong></p>
<li><span "><strong>to aggregate the data in one place and present it in a comprehensible and usable format</strong></span></li>
<p><strong>103. Which wireless parameter is used by an access point to broadcast frames that include the SSID?</strong></p>
<li><span "><strong>passive mode</strong></span></li>
<p><strong>104. Match the field in the Event table of Sguil to the description.</strong></p>
<div style="width: 568px" class="wp-caption aligncenter"><img loading="lazy" decoding="async" class="size-full" src="https://itexamanswers.net/wp-content/uploads/2019/05/Q35Chapter12Answer.jpg" alt="Match the field in the Event table of Sguil to the description" width="558" height="940" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 23"><p class="wp-caption-text">Match the field in the Event table of Sguil to the description</p></div>
<p><strong>105. An employee connects wirelessly to the company network using a cell phone. The employee then configures the cell phone to act as a wireless access point that will allow new employees to connect to the company network. Which type of security threat best describes this situation?</strong></p>
<li><span "><strong>rogue access point</strong></span></li>
<p><strong>106. What information is required for a WHOIS query?</strong></p>
<li><span "><strong>FQDN of the domain</strong></span></li>
<li><span "><strong>They are referred to as a pre-shared key or secret key.</strong></span></li>
<li><span "><strong>They are commonly used with VPN traffic.</strong></span></li>
<p><strong>108. What are two drawbacks to using HIPS? (Choose two.)</strong></p>
<li><span "><strong>With HIPS, the network administrator must verify support for all the different operating systems used in the network.</strong></span></li>
<li><span "><strong>HIPS has difficulty constructing an accurate network picture or coordinating events that occur across the entire network.</strong></span></li>
<p><strong>109. What are three functions provided by the syslog service? (Choose three.)</strong></p>
<li><span "><strong>to select the type of logging information that is captured</strong></span></li>
<li><span "><strong>to gather logging information for monitoring and troubleshooting</strong></span></li>
<li><span "><strong>to specify the destinations of captured messages</strong></span></li>
<p><strong>110. Which consideration is important when implementing syslog in a network?</strong></p>
<li><span "><strong>Synchronize clocks on all network devices with a protocol such as Network Time Protocol.</strong></span></li>
<p><strong>111. What are the two ways threat actors use NTP? (Choose two.)</strong></p>
<li><span "><strong>They attack the NTP infrastructure in order to corrupt the information used to log the attack.</strong></span></li>
<li><span "><strong>Threat actors use NTP systems to direct DDoS attacks.</strong></span></li>
<p><strong>112. Which two features are included by both TACACS+ and RADIUS protocols? (Choose two.)</strong></p>
<li><span "><strong>password encryption</strong></span></li>
<li><span "><strong>utilization of transport layer protocols</strong></span></li>
<p><strong>113. Match the SIEM function to the description.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-58590" src="https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-SIEM-function-to-the-description..jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 23" width="515" height="493" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 24" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-SIEM-function-to-the-description..jpg 515w, https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-SIEM-function-to-the-description.-300x287.jpg 300w" sizes="(max-width: 515px) 100vw, 515px" /></p>
<p><strong>114. What are two types of attacks used on DNS open resolvers? (Choose two.)</strong></p>
<li><span "><strong>amplification and reflection</strong></span></li>
<li><span "><strong>resource utilization</strong></span></li>
<p><strong>115. What are three goals of a port scan attack? (Choose three.)</strong></p>
<li><span "><strong>to determine potential vulnerabilities</strong></span></li>
<li><span "><strong>to identify operating systems</strong></span></li>
<li><span "><strong>to identify active services</strong></span></li>
<p><strong>116. Which protocol or service uses UDP for a client-to-server communication and TCP for server-to-server communication?</strong></p>
<li><span "><strong>DNS</strong></span></li>
<p><strong>117. What is one difference between the client-server and peer-to-peer network models?</strong></p>
<li><span "><strong>Every device in a peer-to-peer network can function as a client or a server.</strong></span></li>
<p><strong>118. Which statement is correct about network protocols?</strong></p>
<li><span "><strong>They define how messages are exchanged between the source and the destination.</strong></span></li>
<p><strong>119. Which approach can help block potential malware delivery methods, as described in the Cyber Kill Chain model, on an Internet-faced web server?</strong></p>
<li><span "><strong>Analyze the infrastructure storage path used for files.</strong></span></li>
<p><strong>120. Which meta-feature element in the Diamond Model classifies the general type of intrusion event?</strong></p>
<li><span "><strong>methodology</strong></span></li>
<p><strong>121. Which Linux command is used to manage processes?</strong></p>
<li><span "><strong>kill</strong></span></li>
<p><strong>122. Which tool can be used in a Cisco AVC system to analyze and present the application analysis data into dashboard reports?</strong></p>
<li><span "><strong>Prime</strong></span></li>
<p><strong>123. Which Windows Event Viewer log includes events regarding the operation of drivers, processes, and hardware?</strong></p>
<li><span "><strong>system logs</strong></span></li>
<p><strong>124. Which method is used to make data unreadable to unauthorized users?</strong></p>
<li><span "><strong>Encrypt the data.</strong></span></li>
<p><strong>125. Match the tabs of the Windows 10 Task Manager to their functions. (Not all options are used.)</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-59071" src="https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-tabs-of-the-Windows-10-Task-Manager-to-their-functions.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 24" width="795" height="813" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 25" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-tabs-of-the-Windows-10-Task-Manager-to-their-functions.jpg 795w, https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-tabs-of-the-Windows-10-Task-Manager-to-their-functions-293x300.jpg 293w, https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-tabs-of-the-Windows-10-Task-Manager-to-their-functions-768x785.jpg 768w" sizes="(max-width: 795px) 100vw, 795px" /></p>
<div class="message_box success"><p><b>Explanation:</b></p>
<table class="table-feedback">
<tbody>
<tr>
<td>Details</td>
<td>Allows for a process to have its affinity set.</td>
</tr>
<tr>
<td>Performance</td>
<td>Displays resource utilization information for CPU, memory, network, disk, and others.</td>
</tr>
<tr>
<td>Startup</td>
<td>Allows programs that are running on system startup to be disabled.</td>
</tr>
<tr>
<td>Services</td>
<td>Allows for a start, stop or restart of a particular service.</td>
</tr>
</tbody>
</table>
<p></p></div>
<p><strong>126. For network systems, which management system addresses the inventory and control of hardware and software configurations?</strong></p>
<li><span "><strong>configuration management</strong></span></li>
<p><strong>127. Match the common network technology or protocol with the description. (Not all options are used.)</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-59072" src="https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-common-network-technology-or-protocol-with-the-description.-Not-all-options-are-used-1603835322.0881.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 25" width="726" height="826" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 26" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-common-network-technology-or-protocol-with-the-description.-Not-all-options-are-used-1603835322.0881.jpg 726w, https://itexamanswers.net/wp-content/uploads/2020/10/Match-the-common-network-technology-or-protocol-with-the-description.-Not-all-options-are-used-1603835322.0881-264x300.jpg 264w" sizes="(max-width: 726px) 100vw, 726px" /></p>
<p><strong>128. What are the three core functions provided by the Security Onion? (Choose three.)</strong></p>
<li><span "><strong>full packet capture</strong></span></li>
<li><span "><strong>alert analysis</strong></span></li>
<li><span "><strong>intrusion detection</strong></span></li>
<p><strong>129. In NAT terms, what address type refers to the globally routable IPv4 address of a destination host on the Internet?</strong></p>
<li><span "><strong>outside global</strong></span></li>
<p><strong>130. Which two fields or features does Ethernet examine to determine if a received frame is passed to the data link layer or discarded by the NIC? (Choose two.)</strong></p>
<li><span "><strong>minimum frame size</strong></span></li>
<li><span "><strong>Frame Check Sequence</strong></span></li>
<p><strong>131. Which type of data would be considered an example of volatile data?</strong></p>
<li><span "><strong>memory registers</strong></span></li>
<p><strong>132. What is the main purpose of exploitations by a threat actor through the weapon delivered to a target during the Cyber Kill Chain exploitation phase?</strong></p>
<li><span "><strong>Break the vulnerability and gain control of the target.</strong></span></li>
<p><strong>133. Refer to the exhibit. An administrator is trying to troubleshoot connectivity between PC1 and PC2 and uses the tracert command from PC1 to do it. Based on the displayed output, where should the administrator begin troubleshooting?</strong></p>
<li><span "><strong>R1</strong></span></li>
<p><strong>134. What three security tools does Cisco Talos maintain security incident detection rule sets for? (Choose three.)</strong></p>
<li><span "><strong>Snort</strong></span></li>
<li><span "><strong>SpamCop</strong></span></li>
<li><span "><strong>ClamAV</strong></span></li>
<p><strong>135. Which host-based firewall uses a three-profile approach to configure the firewall functionality?</strong></p>
<li><span "><strong>Windows Firewall</strong></span></li>
<p><strong>136. When a user visits an online store website that uses HTTPS, the user browser queries the CA for a CRL. What is the purpose of this query?</strong></p>
<li><span "><strong>to verify the validity of the digital certificate</strong></span></li>
<p><strong>137. Which step in the Vulnerability Management Life Cycle determines a baseline risk profile to eliminate risks based on asset criticality, vulnerability threat, and asset classification?</strong></p>
<li><span "><strong>assess</strong></span></li>
<p><strong>138. Which management system implements systems that track the location and configuration of networked devices and software across an enterprise?</strong></p>
<li><span "><strong>asset management</strong></span></li>
<p><strong>139. A network administrator is reviewing server alerts because of reports of network slowness. The administrator confirms that an alert was an actual security incident. What is the security alert classification of this type of scenario?</strong></p>
<li><span "><strong>true positive</strong></span></li>
<p><strong>140. Which application layer protocol is used to provide file-sharing and print services to Microsoft applications?</strong></p>
<li><span "><strong>SMB</strong></span></li>
<p><strong>141. Which device in a layered defense-in-depth approach denies connections initiated from untrusted networks to internal networks, but allows internal users within an organization to connect to untrusted networks?</strong></p>
<li><span "><strong>firewall</strong></span></li>
<p><strong>142. What are two potential network problems that can result from ARP operation? (Choose two.)</strong></p>
<li><span "><strong>On large networks with low bandwidth, multiple ARP broadcasts could cause data communication delays.</strong></span></li>
<p><strong>143. Which three procedures in Sguil are provided to security analysts to address alerts? (Choose three.)</strong></p>
<ul>
<li><span "><strong>Escalate an uncertain alert.</strong></span></li>
<li><span "><strong>Categorize true positives.</strong></span></li>
<li><span "><strong>Expire false positives.</strong></span></li>
<p><strong>144. Match the SOC metric with the description. (Not all options apply.)</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-60153" src="https://itexamanswers.net/wp-content/uploads/2020/11/CyberOps-Associate-1.0-Final-exam_15.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 26" width="730" height="686" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 28" srcset="https://itexamanswers.net/wp-content/uploads/2020/11/CyberOps-Associate-1.0-Final-exam_15.jpg 730w, https://itexamanswers.net/wp-content/uploads/2020/11/CyberOps-Associate-1.0-Final-exam_15-300x282.jpg 300w" sizes="(max-width: 730px) 100vw, 730px" /></p>
<p><strong>145. Which two services are provided by the NetFlow tool? (Choose two.)</strong></p>
<li><span "><strong>usage-based network billing</strong></span></li>
<li><span "><strong>network monitoring</strong></span></li>
<p><strong>146. An administrator discovers that a user is accessing a newly established website that may be detrimental to company security. What action should the administrator take first in terms of the security policy?</strong></p>
<li><span "><strong>Revise the AUP immediately and get all users to sign the updated AUP.</strong></span></li>
<p><strong>147. Which two tasks can be performed by a local DNS server? (Choose two.)</strong></p>
<li><span "><strong>forwarding name resolution requests between servers</strong></span></li>
<li><span "><strong>mapping name-to-IP addresses for internal hosts</strong></span></li>
<p><strong>148. Which type of event is logged in Cisco Next-Generation IPS devices (NGIPS) using FirePOWER Services when changes have been detected in the monitored network?</strong></p>
<li><span "><strong>network discovery</strong></span></li>
<p><strong>149. Which two actions should be taken during the preparation phase of the incident response life cycle defined by NIST? (Choose two.)</strong></p>
<li><span "><strong>Acquire and deploy the tools that are needed to investigate incidents.</strong></span></li>
<li><span "><strong>Create and train the CSIRT.</strong></span></li>
<p><strong>150. What subnet mask is represented by the slash notation /20?</strong></p>
<li><span "><strong>255.255.240.0</strong></span></li>
<p><strong>151. What is the benefit of converting log file data into a common schema?</strong></p>
<li><span "><strong>allows easy processing and analysis of datasets</strong></span></li>
<p><strong>152. Which Cisco sponsored certification is designed to provide the first step in acquiring the knowledge and skills to work with a SOC team?</strong></p>
<li><span "><strong>CCNA CyberOps Associate</strong></span></li>
<p><strong>153. Which three IP addresses are considered private addresses? (Choose three.)</strong></p>
<li><span "><strong>192.168.5.29</strong></span></li>
<li><span "><strong>172.17.254.4</strong></span></li>
<li><span "><strong>10.234.2.1</strong></span></li>
<p><strong>154. When establishing a network profile for an organization, which element describes the time between the establishment of a data flow and its termination?</strong></p>
<li><span "><strong>session duration</strong></span></li>
<p><strong>155. What are the stages that a wireless device completes before it can communicate over a wireless LAN network?</strong></p>
<li><span "><strong>discover a wireless AP, authenticate with the AP, associate with the AP</strong></span></li>
<p><strong>156. Match the correct sequence of steps typically taken by a threat actor carrying out a domain shadowing attack.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-62172" src="https://itexamanswers.net/wp-content/uploads/2020/12/domain-shadow-attack-1608089414.3776.png" alt="Match the correct sequence of steps typically taken by a threat actor carrying out a domain shadowing attack" width="1401" height="1405" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 29" srcset="https://itexamanswers.net/wp-content/uploads/2020/12/domain-shadow-attack-1608089414.3776.png 1401w, https://itexamanswers.net/wp-content/uploads/2020/12/domain-shadow-attack-1608089414.3776-300x300.png 300w, https://itexamanswers.net/wp-content/uploads/2020/12/domain-shadow-attack-1608089414.3776-1021x1024.png 1021w, https://itexamanswers.net/wp-content/uploads/2020/12/domain-shadow-attack-1608089414.3776-150x150.png 150w, https://itexamanswers.net/wp-content/uploads/2020/12/domain-shadow-attack-1608089414.3776-768x770.png 768w" sizes="(max-width: 1401px) 100vw, 1401px" /></p>
<p><strong>157. What are two properties of a cryptographic hash function? (Choose two.)</strong></p>
<li><span "><strong>The output is a fixed length.</strong></span></li>
<li><span "><strong>The hash function is one way and irreversible.</strong></span></li>
<p><strong>158. Refer to the exhibit. The switches have a default configuration. Host A needs to communicate with host D, but host A does not have the MAC address for the default gateway. Which network devices will receive the ARP request sent by host A?</strong></p>
<li><span "><strong>only hosts B, C, and router R1</strong></span></li>
<p><strong>159. Which type of evidence cannot prove an IT security fact on its own?</strong></p>
<li><span "><strong>indirect</strong></span></li>
<p><strong>160. What is a characteristic of a probabilistic analysis in an alert evaluation?</strong></p>
<li><span "><strong>random variables that create difficulty in knowing the outcome of any given event with certainty</strong></span></li>
<p><strong>161. Why would a network administrator choose Linux as an operating system in the Security Operations Center (SOC)?</strong></p>
<li><span "><strong>It can be acquired at no charge.</strong></span></li>
<p><strong>162. A technician needs to verify file permissions on a specific Linux file. Which command would the technician use?</strong></p>
<li><span "><strong>ls -l</strong></span></li>
<p><strong>163. Which two protocols may devices use in the application process that sends email? (Choose two.)</strong></p>
<li><span "><b>DNS</b></span></b></li>
<li><span "><b>SMTP</b></span></b></li>
<p><strong>164. Which file system type was specifically created for optical disk media?</strong></p>
<li><span "><b>CDFS</b></span></b></li>
<p><strong>165. A piece of malware has gained access to a workstation and issued a DNS lookup query to a CnC server. What is the purpose of this attack?</strong></p>
<li><span "><strong>to send stolen sensitive data with encoding</strong></span></li>
<p><strong>166. Refer to the exhibit. Which field in the Sguil event window indicates the number of times an event is detected for the same source and destination IP address?</strong><br />
<li><span "><strong>CNT</strong></span></li>
<p><strong>167. Refer to the exhibit. The IP address of which device interface should be used as the default gateway setting of host H1?</strong><br />
<li><span "><strong>R1: G0/0</strong></span></li>
<p><strong>168. According to information outlined by the Cyber Kill Chain, which two approaches can help identify reconnaissance threats? (Choose two.)</strong></p>
<li><span "><strong>Analyze web log alerts and historical search data.</strong></span></li>
<li><span "><strong>Build playbooks for detecting browser behavior.</strong></span></li>
<p><strong>169. Which two ICMPv6 messages are used during the Ethernet MAC address resolution process? (Choose two.)</strong></p>
<li><span>neighbor solicitation </span></strong></li>
<li><span>neighbor advertisement</span></strong></li>
<p><strong>170. What best describes the destination IPv4 address that is used by multicasting?</strong></p>
<li><span "><strong>a single IP multicast address that is used by all destinations in a group</strong></span></li>
<p><strong>171. What is the result of using security devices that include HTTPS decryption and inspection services?</strong></p>
<li><span "><strong>The devices introduce processing delays and privacy issues.</strong></span></li>
<p><strong>172. What is a disadvantage of DDNS?</strong></p>
<li><span "><strong>Using free DDNS services, threat actors can quickly and easily generate subdomains and change DNS records.</strong></span></li>
<p><strong>173. Match the network-based antimalware solution to the function. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter wp-image-65715" src="https://itexamanswers.net/wp-content/uploads/2020/09/CyberOps-Associate-Version-1.0-CyberOps-Associate-1.0-Final-exam-Answers-003-994x1024-1.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 29" width="700" height="721" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 33" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/CyberOps-Associate-Version-1.0-CyberOps-Associate-1.0-Final-exam-Answers-003-994x1024-1.png 994w, https://itexamanswers.net/wp-content/uploads/2020/09/CyberOps-Associate-Version-1.0-CyberOps-Associate-1.0-Final-exam-Answers-003-994x1024-1-291x300.png 291w, https://itexamanswers.net/wp-content/uploads/2020/09/CyberOps-Associate-Version-1.0-CyberOps-Associate-1.0-Final-exam-Answers-003-994x1024-1-768x791.png 768w" sizes="(max-width: 700px) 100vw, 700px" /></p>
<p><strong>174. A threat actor has identified the potential vulnerability of the web server of an organization and is building an attack. What will the threat actor possibly do to build an attack weapon?</strong></p>
<li><span "><strong>Obtain an automated tool in order to deliver the malware payload through the vulnerability.</strong></span></li>
<p><strong>175. Which tool included in the Security Onion is a series of software plugins that send different types of data to the Elasticsearch data stores?</strong></p>
<li><span>Beats</span></strong></li>
<p><strong>176. Which term is used to describe the process of identifying the NSM-related data to be gathered?</strong></p>
<li><span>data reduction</span></strong></li>
<p><strong>177. Match the alert classification with the description.</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-65717" src="https://itexamanswers.net/wp-content/uploads/2020/09/2021-04-16_143615.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 30" width="759" height="599" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 34" srcset="https://itexamanswers.net/wp-content/uploads/2020/09/2021-04-16_143615.jpg 759w, https://itexamanswers.net/wp-content/uploads/2020/09/2021-04-16_143615-300x237.jpg 300w" sizes="(max-width: 759px) 100vw, 759px" /></p>
<p><strong>178. According to NIST, which step in the digital forensics process involves preparing and presenting information that resulted from scrutinizing data?</strong></p>
<li><span>reporting</span></strong></li>
<p><strong>179. Refer to the exhibit. A cybersecurity analyst is using Sguil to verify security alerts. How is the current view sorted?</strong></p>
<li><span>by frequency</span></strong></li>
<p><strong>180. Which two options are window managers for Linux? (Choose two.)</strong></p>
<li><span>Gnome</span></strong></li>
<li><span "><strong>KDE</strong></span></li>
<p><strong>181. What are the two methods that a wireless NIC can use to discover an AP? (Choose two.)</strong></p>
<li><span>transmitting a probe request</span></strong></li>
<li><span "><strong>receiving a broadcast beacon frame</strong></span></li>
<p><strong>182. A client device has initiated a secure HTTP request to a web browser. Which well-known port address number is associated with the destination address?</strong></p>
<li><span>443</span></strong></li>
<p><strong>183. Which term describes evidence that is in its original state?</strong></p>
<li><span "><strong>Best evidence</strong></span></li>
<p><strong>184. Which three statements describe a DHCP Discover message? (Choose three.)</strong></p>
<li><span ">The destination IP address is 255.255.255.255.</span></li>
<li><span ">The message comes from a client seeking an IP address.</span></li>
<li><span ">All hosts receive the message, but only a DHCP server replies.</span></li>
<p><strong>185. Refer to the exhibit. The PC is sending a packet to the Server on the remote network. Router R1 is performing NAT overload. From the perspective of the PC, match the NAT address type with the correct IP address. (Not all options are used.)</strong></p>
<li><span "><strong>prioritize assets</strong></span></li>
<p><strong>187. A client application needs to terminate a TCP communication session with a server. Place the termination process steps in the order that they will occur. (Not all options are used.)</strong></p>
<p><img loading="lazy" decoding="async" class="aligncenter size-full wp-image-56804" src="https://itexamanswers.net/wp-content/uploads/2020/03/CCNA1-v7-ITN-Network-Application-Communications-Exam-Answers-001.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 34" width="726" height="742" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 38" srcset="https://itexamanswers.net/wp-content/uploads/2020/03/CCNA1-v7-ITN-Network-Application-Communications-Exam-Answers-001.png 726w, https://itexamanswers.net/wp-content/uploads/2020/03/CCNA1-v7-ITN-Network-Application-Communications-Exam-Answers-001-294x300.png 294w" sizes="(max-width: 726px) 100vw, 726px" /><br />
<p><strong>188. Match the attack vector with the description.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-72589" src="https://itexamanswers.net/wp-content/uploads/2020/10/2021-12-28_152547.png" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 35" width="649" height="488" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 39" srcset="https://itexamanswers.net/wp-content/uploads/2020/10/2021-12-28_152547.png 649w, https://itexamanswers.net/wp-content/uploads/2020/10/2021-12-28_152547-300x226.png 300w" sizes="(max-width: 649px) 100vw, 649px" /></p>
<p><strong>189. Match the security management function with the description.</strong></p>
<div id="attachment_72605" style="width: 653px" class="wp-caption aligncenter"><img loading="lazy" decoding="async" aria-describedby="caption-attachment-72605" class="size-full wp-image-72605" src="https://itexamanswers.net/wp-content/uploads/2022/01/question30-1639433305.8688.png" alt="CyberOps Associate (Version 1.0) – CyberOps Associate 1.0 Final exam answers 189" width="643" height="649" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 40" srcset="https://itexamanswers.net/wp-content/uploads/2022/01/question30-1639433305.8688.png 643w, https://itexamanswers.net/wp-content/uploads/2022/01/question30-1639433305.8688-297x300.png 297w, https://itexamanswers.net/wp-content/uploads/2022/01/question30-1639433305.8688-150x150.png 150w, https://itexamanswers.net/wp-content/uploads/2022/01/question30-1639433305.8688-80x80.png 80w, https://itexamanswers.net/wp-content/uploads/2022/01/question30-1639433305.8688-75x75.png 75w" sizes="(max-width: 643px) 100vw, 643px" /><p id="caption-attachment-72605" class="wp-caption-text">CyberOps Associate (Version 1.0) – CyberOps Associate 1.0 Final exam answers Q189</p></div>
<p><strong>190. What are two functions that are provided by the network layer? (Choose two.)</strong></p>
<li><span ">directing data packets to destination hosts on other networks</span></li>
<li><span ">providing end devices with a unique network identifier</span></li>
<p><strong>191. Match the phase in the NIST incident response life cycle to the action.</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-90042" src="https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_080521.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 36" width="1131" height="769" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 41" srcset="https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_080521.jpg 1131w, https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_080521-300x204.jpg 300w, https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_080521-1024x696.jpg 1024w, https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_080521-768x522.jpg 768w" sizes="(max-width: 1131px) 100vw, 1131px" /></p>
<p><strong>192. Match the Linux CLI commands to their function. (Not all options are used.)</strong><br />
<img loading="lazy" decoding="async" class="aligncenter size-full wp-image-90044" src="https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_083156.jpg" alt="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 37" width="679" height="872" title="CyberOps Associate (Version 1.0) - FINAL Exam (Answers) 42" srcset="https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_083156.jpg 679w, https://itexamanswers.net/wp-content/uploads/2023/04/2023-04-29_083156-234x300.jpg 234w" sizes="(max-width: 679px) 100vw, 679px" /></p>
