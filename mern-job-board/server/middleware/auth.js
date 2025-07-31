import { expressjwt } from 'express-jwt';
import jwksRsa from 'jwks-rsa';

const checkJwt = expressjwt({
  secret: jwksRsa.expressJwtSecret({
    cache: true,
    rateLimit: true,
    jwksUri: 'https://cognito-idp.us-east-2.amazonaws.com/us-east-2_tn5VlFF4Q/.well-known/jwks.json'
  }),
  audience: '3ep3v70csbgoi3l4bph9m2hlcm', // your Cognito App Client ID
  issuer: 'https://cognito-idp.us-east-2.amazonaws.com/us-east-2_tn5VlFF4Q',
  algorithms: ['RS256']
});

export default checkJwt;
