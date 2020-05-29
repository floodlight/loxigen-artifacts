// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFRequestforwardVer15 implements OFRequestforward {
    private static final Logger logger = LoggerFactory.getLogger(OFRequestforwardVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 16;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static long DEFAULT_XID = 0x0L;

    // OF message fields
    private final long xid;
    private final OFMessage request;
//

    // package private constructor - used by readers, builders, and factory
    OFRequestforwardVer15(long xid, OFMessage request) {
        if(request == null) {
            throw new NullPointerException("OFRequestforwardVer15: property request cannot be null");
        }
        this.xid = U32.normalize(xid);
        this.request = request;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public OFType getType() {
        return OFType.REQUESTFORWARD;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public long getRole()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property role not supported in version 1.5");
    }

    @Override
    public byte[] getData()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }

    @Override
    public OFMessage getRequest() {
        return request;
    }



    public OFRequestforward.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFRequestforward.Builder {
        final OFRequestforwardVer15 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean requestSet;
        private OFMessage request;

        BuilderWithParent(OFRequestforwardVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public OFType getType() {
        return OFType.REQUESTFORWARD;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFRequestforward.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public long getRole()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property role not supported in version 1.5");
    }

    @Override
    public OFRequestforward.Builder setRole(long role) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property role not supported in version 1.5");
    }
    @Override
    public byte[] getData()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }

    @Override
    public OFRequestforward.Builder setData(byte[] data) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }
    @Override
    public OFMessage getRequest() {
        return request;
    }

    @Override
    public OFRequestforward.Builder setRequest(OFMessage request) {
        this.request = request;
        this.requestSet = true;
        return this;
    }


        @Override
        public OFRequestforward build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                OFMessage request = this.requestSet ? this.request : parentMessage.request;
                if(request == null)
                    throw new NullPointerException("Property request must not be null");

                //
                return new OFRequestforwardVer15(
                    xid,
                    request
                );
        }

    }

    static class Builder implements OFRequestforward.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean requestSet;
        private OFMessage request;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

    @Override
    public OFType getType() {
        return OFType.REQUESTFORWARD;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFRequestforward.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public long getRole()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property role not supported in version 1.5");
    }

    @Override
    public OFRequestforward.Builder setRole(long role) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property role not supported in version 1.5");
    }
    @Override
    public byte[] getData()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }

    @Override
    public OFRequestforward.Builder setData(byte[] data) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property data not supported in version 1.5");
    }
    @Override
    public OFMessage getRequest() {
        return request;
    }

    @Override
    public OFRequestforward.Builder setRequest(OFMessage request) {
        this.request = request;
        this.requestSet = true;
        return this;
    }
//
        @Override
        public OFRequestforward build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            if(!this.requestSet)
                throw new IllegalStateException("Property request doesn't have default value -- must be set");
            if(request == null)
                throw new NullPointerException("Property request must not be null");


            return new OFRequestforwardVer15(
                    xid,
                    request
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFRequestforward> {
        @Override
        public OFRequestforward readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 6
            byte version = bb.readByte();
            if(version != (byte) 0x6)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_15(6), got="+version);
            // fixed value property type == 32
            byte type = bb.readByte();
            if(type != (byte) 0x20)
                throw new OFParseError("Wrong type: Expected=OFType.REQUESTFORWARD(32), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            OFMessage request = OFMessageVer15.READER.readFrom(bb);

            OFRequestforwardVer15 requestforwardVer15 = new OFRequestforwardVer15(
                    xid,
                      request
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", requestforwardVer15);
            return requestforwardVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFRequestforwardVer15Funnel FUNNEL = new OFRequestforwardVer15Funnel();
    static class OFRequestforwardVer15Funnel implements Funnel<OFRequestforwardVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFRequestforwardVer15 message, PrimitiveSink sink) {
            // fixed value property version = 6
            sink.putByte((byte) 0x6);
            // fixed value property type = 32
            sink.putByte((byte) 0x20);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            message.request.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFRequestforwardVer15> {
        @Override
        public void write(ByteBuf bb, OFRequestforwardVer15 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 6
            bb.writeByte((byte) 0x6);
            // fixed value property type = 32
            bb.writeByte((byte) 0x20);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            message.request.writeTo(bb);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFRequestforwardVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFRequestforwardVer15(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("request=").append(request);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFRequestforwardVer15 other = (OFRequestforwardVer15) obj;

        if( xid != other.xid)
            return false;
        if (request == null) {
            if (other.request != null)
                return false;
        } else if (!request.equals(other.request))
            return false;
        return true;
    }

    @Override
    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFRequestforwardVer15 other = (OFRequestforwardVer15) obj;

        // ignore XID
        if (request == null) {
            if (other.request != null)
                return false;
        } else if (!request.equals(other.request))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((request == null) ? 0 : request.hashCode());
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime * result + ((request == null) ? 0 : request.hashCode());
        return result;
    }

}
