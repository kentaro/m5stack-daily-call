// https://www.gesource.jp/weblog/?p=8082
var mdns = require('multicast-dns')();

mdns.on('response', function (response) {
    let name = '';
    let ip = '';
    for (const additional of response.additionals) {
        if (additional.type == 'TXT') name = additional.name;
        if (additional.type == 'A') ip = additional.data;
    }
    if (name != '') console.log(`${name}(${ip})`);
});

mdns.query({
    questions: [{
        name: '_googlecast._tcp.local',
        type: 'PTR'
    }]
});